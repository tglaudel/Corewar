/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/05 13:20:45 by tglaudel         ###   ########.fr       */
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
			return (2);
		}
	}
	size = parsing_argument(proc, mem, i);
	proc->exec = 1;
	return (size);
}

static void		exe_instruction(t_proc *proc, t_env *e)
{
	if (proc->inst.opc == 1)
		live(e, proc);
	else if (proc->inst.opc == 2)
		ld(e, proc);
	else if (proc->inst.opc == 3)
		st(e, proc);
	else if (proc->inst.opc == 4)
		add(e, proc);
	else if (proc->inst.opc == 5)
		sub(e, proc);
	else if (proc->inst.opc == 6)
		and(e, proc);
	else if (proc->inst.opc == 7)
		or(e, proc);
	else if (proc->inst.opc == 8)
		xor(e, proc);
	else if (proc->inst.opc == 9)
		zjmp(e, proc);
	else if (proc->inst.opc == 10)
		ldi(e, proc);
	else if (proc->inst.opc == 12)
		new_processus(e, e->nb_proc, proc->pos + 5, proc);
	mvchgat(proc->pos / 64, proc->pos % 64 * 3, 2, A_BLINK, 10, NULL);
	proc->pos = proc->pc;
}

static int		define_opc(t_proc *proc, unsigned char *mem)
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
	int size;

	proc = e->proc_start;
	while (proc)
	{
		//ft_printf("%d %d\n", proc->index, proc->inst.opc);
		size = -1;
		if (proc->wait_cycle > 0)
			--proc->wait_cycle;
		else if (proc->wait_cycle == 0 && proc->inst.opc != 0)
		{
			if ((size = parsing_instruction(proc, e->mem)) != -1)
				proc->pc = (proc->pos + size) % MEM_SIZE;
			if (proc->exec == 1)
				exe_instruction(proc, e);
			init_proc(proc);
		}
		else if (!define_opc(proc, e->mem))
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
		proc_loop(e);
		++e->nb_cycle;
		// system("clear");
		// print_memory(e, e->mem, e->proc_start);
		usleep(10000);
		if (before_check_die == e->c_to_die)
		{
			check_proc_cycle(e);
			re_init_proc(e->proc_start);
			before_check_die = 0;
			e->global_live = 0;
		}
		++before_check_die;
		if (e->verbose & VERBOSE_CYCLE)
			ft_printf("It is now cycle %d\n", e->nb_cycle);
		if (have_opt('n', e->opt))
		{
			print_processus(e->proc_start);
			refresh();
		}
	}
}
