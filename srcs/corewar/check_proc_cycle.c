/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proc_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:16:05 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 11:46:48 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int				iter_del_proc(t_proc *start, t_env *e)
{
	t_proc *proc_prev;
	t_proc *proc;
	int i;

	i = 0;
	proc_prev = start;
	while (proc_prev && proc_prev->next)
	{
		proc = proc_prev->next;
		if (proc->live_exec >= e->c_to_die)
		{
			proc_prev->next = proc->next;
			if (e->verbose & VERBOSE_DIE)
				printf("Process %d hasn't lived for %d cycles (CTD %d)\n",\
				proc->index, proc->live_exec, e->c_to_die);
			free(proc->r);
			proc->r = NULL;
			free(proc);
			proc = NULL;
			i++;
		}
		else
			proc_prev = proc_prev->next;
	}
	return (i);
}

int					del_proc(t_proc *start, t_env *e)
{
	t_proc 	*proc;
	int		nb_proc_die;

	proc = start;
	while (proc && proc->live_exec >= e->c_to_die)
	{
		if (e->verbose & VERBOSE_DIE)
			printf("Process %d hasn't lived for %d cycles (CTD %d)\n",\
			proc->index, proc->live_exec, e->c_to_die);
		e->proc_start = proc->next;
		--e->nb_proc_in_life;
		free(proc->r);
		proc->r = NULL;
		free(proc);
		proc = e->proc_start;
	}
	if (e->proc_start == NULL)
		return (0);
	if ((nb_proc_die = iter_del_proc(proc, e)) > 0)
	{
		e->nb_proc_in_life -= nb_proc_die;
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
		if (!have_opt('c', e->opt) && (e->verbose & VERBOSE_CYCLE) == VERBOSE_CYCLE)
			printf("Cycle to die is now %d\n", e->c_to_die);
		e->nb_check_td = 0;
	}
	else
	{
		e->nb_check_td++;
		if (e->nb_check_td == MAX_CHECKS)
		{
			e->c_to_die -= CYCLE_DELTA;
			e->nb_check_td = 0;
			if (!have_opt('c', e->opt) && (e->verbose & VERBOSE_CYCLE) == VERBOSE_CYCLE)
				printf("Cycle to die is now %d\n", e->c_to_die);
		}
	}
	if (e->verbose & VERBOSE_DEBUG)
		print_processus_debug(e->proc_start, e->nb_cycle);
	e->global_live = 0;
}
