/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_proc_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 14:16:05 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/01 19:03:53 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int			recurse_del_proc(t_proc *prev_proc, t_proc *proc)
{
	if (proc == NULL)
		return (1);
	if (proc->live_exec == 0)
	{
		ft_printf("del proc : %d -> live %d\n", proc->index, proc->live_exec);
		prev_proc->next = proc->next;
		free(proc);
		return (recurse_del_proc(prev_proc, proc->next) + 1);
	}
	return (recurse_del_proc(proc, proc->next));
}

int					del_proc(t_proc *start, t_env *e)
{
	t_proc 	*proc;
	int		nb_proc_die;

	proc = start;
	while (start && proc && start->live_exec == 0)
	{
		ft_printf("del proc : %d -> cycle %d -> live %d\n", proc->index, e->nb_cycle, proc->live_exec);
		start = proc->next;
		--e->nb_proc;
		free(proc);
		proc = start;
	}
	if (start == NULL)
		return (0);
	if ((nb_proc_die = recurse_del_proc(proc, proc->next)) > 1)
	{
		e->nb_proc -= nb_proc_die + 1;
		return (1);
	}
	return (0);
}

void				check_proc_cycle(t_env *e)
{
	if (del_proc(e->proc_start, e))
		e->c_to_die = e->c_to_die - CYCLE_DELTA;
	else
	{
		if (e->nb_check_td == MAX_CHECKS)
		{
			e->c_to_die = e->c_to_die - CYCLE_DELTA;
			e->nb_check_td = 0;
		}
		e->nb_check_td++;
	}
}


// int			check_proc_to_die(t_proc *start)
// {
// 	t_proc *proc;
// 	t_proc *next_proc;
// 	int proc_die;
//
// 	proc_die = 0;
// 	proc = start;
// 	while (proc) ATTENTION LES YEUX NONONONON
// 	{
// 		next_proc = proc->next;
// 		if (next_proc && next_proc->live_exec == 0)
// 		{
// 			proc->next = next_proc->next;
// 			proc_die += del_one_proc(next_proc->index);
// 		}
// 		proc = next_proc;
// 	}
// 	return (proc_die);
// }

//faut voir si ca fonctionne
