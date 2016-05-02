/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/02 19:01:40 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"
#include <stdio.h>

static int 		define_instruction(t_env *e, t_proc *proc, unsigned char *mem)
{
	int size;

	if ((size = parsing_instruction(proc, mem)) == -1)
	{
		proc->pos = ++proc->pos % MEM_SIZE;
	}
	else
	{
		if (e->verbose & VERBOSE_OP)
			print_op(proc, proc->inst.opc - 1, e->nb_cycle);
		return (size);
	}
	return (-1);
}

static void		exe_instruction(t_proc *proc, t_env *e)
{
	if (proc->inst.opc == 1)
		live(e, proc);
	else if (proc->inst.opc == 12)
		new_processus(e, e->nb_proc, proc->pos + 5, proc);
	proc->pos = proc->pc;
	ft_putnbr(e->global_live);
	init_proc(proc);
}

static void		proc_loop(t_env *e)
{
	t_proc *proc;
	int size;

	proc = e->proc_start;
	while (proc)
	{
		size = -1;
		if (proc->wait_cycle > 0)
			--proc->wait_cycle;
		else if (proc->wait_cycle == 0 && proc->inst.opc != 0)
		{
			exe_instruction(proc, e);
			if ((size = define_instruction(e, proc, e->mem)))
				proc->pc = (proc->pos + size) % MEM_SIZE;
		}
		else if ((size = define_instruction(e, proc, e->mem)))
			proc->pc = (proc->pos + size) % MEM_SIZE;
		proc = proc->next;
	}
}

void		game_loop(t_env *e)
{
	int before_check_die;

	before_check_die = 0;
	while (e->nb_champ > 0 && e->nb_proc > 0 &&\
	e->nb_cycle < e->nb_cycle_max)
	{
		proc_loop(e);
		++e->nb_cycle;
		++before_check_die;
		if (e->verbose & VERBOSE_CYCLE)
			ft_printf("It is now cycle %d -> %d \n", e->nb_cycle, e->nb_proc);
		// system("clear");
		// print_memory(e, e->mem, e->proc_start);
		// usleep(10000);
		if (have_opt('n', e->opt))
			print_board(e);
		if (before_check_die == e->c_to_die)
		{
			check_proc_cycle(e);
			re_init_proc(e->proc_start);
			before_check_die = 0;
		}
	}
}
