/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proc_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:16:05 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/06 11:16:32 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int			recurse_del_proc(t_proc *prev_proc, t_proc *proc, int verb)
{
	if (proc == NULL)
		return (1);
	if (proc->live_exec == 0)
	{
		if (verb)
			ft_printf("del proc: %d ->live %d\n", proc->index, proc->live_exec);
		prev_proc->next = proc->next;
		free(proc);
		return (recurse_del_proc(prev_proc, proc->next, verb) + 1);
	}
	return (recurse_del_proc(proc, proc->next, verb));
}

int					del_proc(t_proc *start, t_env *e)
{
	t_proc 	*proc;
	int		nb_proc_die;

	proc = start;
	while (e->proc_start && e->proc_start->live_exec == 0)
	{
		if (e->verbose & VERBOSE_DEBUG)
			ft_printf("del proc : %d -> cycle %d -> live %d\n", proc->index,\
			e->nb_cycle, proc->live_exec);
		e->proc_start = proc->next;
		--e->nb_proc;
		free(proc);
		proc = e->proc_start;
	}
	if (e->proc_start == NULL)
		return (0);
	if ((nb_proc_die = recurse_del_proc(proc, proc->next,\
		(e->verbose & VERBOSE_DEBUG))) > 1)
	{
		e->nb_proc -= nb_proc_die + 1;
		return (1);
	}
	return (0);
}

void				check_proc_cycle(t_env *e)
{
	del_proc(e->proc_start, e);
	if (e->global_live >= NBR_LIVE)
	{
		e->c_to_die -= CYCLE_DELTA;
		if (!have_opt('n', e->opt))
			ft_printf("Cycle to die is now %d\n", e->c_to_die);
		//e->nb_check_td = 0;
	}
	else
	{
		e->nb_check_td++;
		if (e->nb_check_td == MAX_CHECKS)
		{
			e->c_to_die -= CYCLE_DELTA;
			e->nb_check_td = 0;
			ft_printf("Cycle to die is now %d\n", e->c_to_die);
		}
	}
	if (e->verbose & VERBOSE_DEBUG)
		print_processus_debug(e->proc_start, e->nb_cycle);
}
