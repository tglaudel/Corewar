/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:01:32 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/02 18:56:54 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			is_prog_pos(t_proc *start, int x, int y)
{
	t_proc *tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->pos % 64 == y && tmp->pos / 64 == x)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		new_processus(t_env *e, int nb, int pos, t_proc *papa)
{
	t_proc *proc;

	++e->nb_proc;
	if (!(proc = (t_proc*)malloc(sizeof(t_proc))))
		ft_errors("ERROR : Error malloc", 1, 0);
	proc->next = NULL;
	if (e->proc_start != NULL)
		proc->next = e->proc_start;
	e->proc_start = proc;
	bzero(proc->r, REG_NUMBER);
	if (e->verbose & VERBOSE_DEBUG)
		ft_printf("creation proc : %d -> cycle %d\n", e->nb_proc, e->nb_cycle);
	proc->r[0] = nb;
	if (papa)
		proc->r[0] = papa->r[0];
	proc->pos = pos;
	proc->index = e->nb_proc;
	proc->wait_cycle = 0;
	proc->carry = 0;
	proc->live_exec = 0;
	init_proc(proc);
}
