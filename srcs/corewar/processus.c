/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:01:32 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/05 11:57:18 by tglaudel         ###   ########.fr       */
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

static void copie_proc(t_proc *new, t_proc *papa)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		new->r[i] = papa->r[i];
	new->pos = papa->pos + 5;//papa->inst.arg[0]; // attention au % MEM_SIZE et au signe
	new->wait_cycle = 0;
	new->carry = papa->carry;
	new->live_exec = papa->live_exec;
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
	if (e->verbose & VERBOSE_DEBUG)
		ft_printf("creation proc : %d -> cycle %d\n", e->nb_proc, e->nb_cycle);
	if (papa)
		copie_proc(proc, papa);
	else
	{
		bzero(proc->r, REG_NUMBER);
		proc->r[0] = nb;
		proc->pos = pos;
		proc->index = e->nb_proc;
		proc->wait_cycle = 0;
		proc->carry = 0;
		proc->live_exec = 0;
	}
	proc->exec = 0;
	init_proc(proc);
}
