/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:59:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/11 21:58:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void		re_init_proc(t_proc *start)
{
	t_proc *proc;

	proc = start;
	while(proc)
	{
		proc->live_exec = 0;
		proc = proc->next;
	}
}

void init_proc(t_proc *proc)
{
	proc->pc = 0;
	proc->inst.opc = 0;
	proc->inst.odc = 0;
	proc->inst.arg[0] = 0;
	proc->inst.arg[1] = 0;
	proc->inst.arg[2] = 0;
	proc->inst.size = 0;
	proc->exec = 0;
	proc->pc = 0;
}

void		init_env(t_env *e)
{
	e->champ_start = NULL;
	e->champ_end = NULL;
	e->proc_start = NULL;
	if (e->nb_cycle_max == -1)
		e->nb_cycle_max = 2147483647;
	e->nb_cycle = 0;
	e->nb_champ = 0;
	e->width = 0;
	e->c_to_die = CYCLE_TO_DIE;
	e->nb_proc = 0;
	e->nb_check_td = 0;
	e->global_live = 0;
	e->nb_proc_in_life = 0;
	e->speed = 10000;
	e->speed_mult = 0;
	ft_bzero(e->mem, MEM_SIZE + 1);
	ft_bzero(e->col, MEM_SIZE + 1);
}

void		init_cor(t_env *e, char **av)
{
	int i;
	int nb;

	nb = 0;
	i = -1;
	init_env(e);
	while (av[++i])
	{
		if (is_champ(av[i], e) != -1)
		{
			nb++;
			if (nb == 1 && !have_opt('c', e->opt))
				ft_putendl("Introducing contestants...");
			if (nb > 4)
				ft_errors("ERROR : Nb champs > 4.", 1, 0);
			add_to_champ_lst(e, nb, e->width, av[i]);
		}
		// debug width
		// printf("%d\n", e->width);
	}
	e->nb_champ = nb;
	insert_in_memory(e);
}
