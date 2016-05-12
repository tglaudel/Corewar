/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 23:14:06 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int			parsing_instruction(t_proc *proc, unsigned char *mem)
{
	int i;
	int size;

	i = -1;
	size = 0;
	while (g_op_tab[++i].op_code != 0)
		if (g_op_tab[i].op_code == proc->inst.opc)
			break ;
	if (g_op_tab[i].codage_code == 1)
	{
		proc->inst.odc = mem[(proc->pos + 1) % MEM_SIZE];
		if (!check_odc(proc, i))
		{
			proc->exec = 0;
			return (error_odc(proc, i));
		}
	}
	size = parsing_argument(proc, mem, i);
	proc->exec = 1;
	return (size);
}

static void			exe_instruction(t_proc *proc, t_env *e)
{
	int i;

	i = -1;
	while (g_op_tab[++i].nb_arg)
	{
		if (proc->inst.opc == g_op_tab[i].op_code)
		{
			g_op_tab[i].f(e, proc);
			if ((e->verbose & VERBOSE_PC) == VERBOSE_PC)
				print_adv(proc, e, 1);
			mvchgat(proc->pos / 64, proc->pos % 64 * 3, 2, A_NORMAL,\
			proc->champ_color, NULL);
			proc->pos = proc->pc;
			break ;
		}
	}
	proc->pos = proc->pc;
}

static void			pre_exec(t_env *e, t_proc *proc)
{
	if ((proc->inst.size = parsing_instruction(proc, e->mem)) != -1)
		proc->pc = (proc->pos + proc->inst.size) % MEM_SIZE;
	if (proc->exec == 1)
		exe_instruction(proc, e);
	else
	{
		if ((e->verbose & VERBOSE_PC) == VERBOSE_PC)
			print_adv(proc, e, 1);
		proc->pos = proc->pc;
	}
	init_proc(proc);
}

static void			proc_loop(t_env *e)
{
	t_proc *proc;

	proc = e->proc_start;
	while (proc)
	{
		++proc->live_exec;
		if (proc->wait_cycle > 0)
			--proc->wait_cycle;
		if (proc->inst.opc == 0)
			define_opc(proc, e->mem);
		if (proc->inst.opc != 0 && proc->wait_cycle == 0)
			pre_exec(e, proc);
		else if (proc->wait_cycle == 0)
			proc->pos = ++proc->pos % MEM_SIZE;
		proc = proc->next;
	}
}

void				game_loop(t_env *e)
{
	int before_check_die;

	before_check_die = 0;
	print_board(e);
	while (e->nb_proc_in_life > 0 && e->nb_cycle < e->nb_cycle_max)
	{
		++e->nb_cycle;
		if (before_check_die >= e->c_to_die)
		{
			check_champ_cycle(e);
			check_proc_cycle(e);
			before_check_die = 0;
			if (e->nb_proc_in_life == 0)
				return ;
		}
		++before_check_die;
		if (e->verbose & VERBOSE_CYCLE)
			printf("It is now cycle %d\n", e->nb_cycle);
		proc_loop(e);
		if (have_opt('c', e->opt))
			ncurses_loop(e);
	}
	if (!have_opt('c', e->opt) && have_opt('d', e->opt))
		print_memory(e->mem);
}
