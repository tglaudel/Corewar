/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/09 19:41:25 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int		parsing_instruction(t_proc *proc, unsigned char *mem)
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

static void		exe_instruction(t_proc *proc, t_env *e)
{
	int i;

	i = -1;
	while (g_op_tab[++i].nb_arg)
	{
		if (proc->inst.opc == g_op_tab[i].op_code)
		{
			g_op_tab[i].f(e, proc);
			if ((e->verbose & VERBOSE_PC) == VERBOSE_PC)
				print_adv(proc, e);
			proc->pos = proc->pc;
			break ;
		}
	}
	mvchgat(proc->pos / 64, proc->pos % 64 * 3, 2, A_NORMAL,\
	proc->champ_color, NULL);
	proc->pos = proc->pc;
}

int		define_opc(t_proc *proc, unsigned char *mem)
{
	int i;

	i = -1;
	while (g_op_tab[++i].op_code != 0)
	{
		if (g_op_tab[i].op_code == mem[proc->pos])
		{
			proc->wait_cycle = g_op_tab[i].wait_before_exe - 1;
			proc->inst.opc = g_op_tab[i].op_code;
			return (1);
		}
	}
	return (0);
}

static void		proc_loop(t_env *e)
{
	t_proc *proc;

	proc = e->proc_start;
	while (proc)
	{
		if (proc->wait_cycle > 0)
			--proc->wait_cycle;
		if (proc->inst.opc == 0)
			define_opc(proc, e->mem);
		if (proc->inst.opc != 0 && proc->wait_cycle == 0)
		{
			if ((proc->inst.size = parsing_instruction(proc, e->mem)) != -1)
				proc->pc = (proc->pos + proc->inst.size) % MEM_SIZE;
			if (proc->exec == 1)
				exe_instruction(proc, e);
			else
			{
				if ((e->verbose & VERBOSE_PC) == VERBOSE_PC)
					print_adv(proc, e);
				proc->pos = proc->pc;
			}
			init_proc(proc);
		}
		else if (proc->wait_cycle == 0)
			proc->pos = ++proc->pos % MEM_SIZE;
		proc = proc->next;
	}
}

void		game_loop(t_env *e)
{
	int before_check_die;

	before_check_die = 0;
	print_board(e);
	while (e->nb_champ > 0 && e->nb_proc > 0 &&\
	e->nb_cycle < e->nb_cycle_max && e->c_to_die > 0)
	{
		if (before_check_die == e->c_to_die)
		{
			check_champ_cycle(e);
			check_proc_cycle(e);
			re_init_proc(e->proc_start);
			before_check_die = 0;
			e->global_live = 0;
		}
		++before_check_die;
		++e->nb_cycle;
		if (e->verbose & VERBOSE_CYCLE)
			ft_printf("It is now cycle %d\n", e->nb_cycle);
		proc_loop(e);
		if (have_opt('c', e->opt))
			ncruses_loop(e);
	}
	if (!have_opt('c', e->opt) && have_opt('d', e->opt))
		print_memory(e->mem);
}
