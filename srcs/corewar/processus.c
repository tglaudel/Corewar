/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:01:32 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/09 16:16:25 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static void copie_proc(t_proc *new, t_proc *papa, int pos, t_env *e)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		new->r[i] = papa->r[i];
	new->pos = pos;
	new->wait_cycle = 0;
	new->carry = papa->carry;
	new->live_exec = papa->live_exec;
	new->champ_color = papa->champ_color;
	new->inst.odc = 0;
	new->inst.size = 0;
	bzero(new->inst.arg, 3);
	new->exec = 0;
	if (!define_opc(new, e->mem))
		new->pos = ++new->pos % MEM_SIZE;
}

void		new_processus(t_env *e, int nb, int pos, t_proc *papa)
{
	t_proc *proc;

	++e->nb_proc;
	++e->nb_proc_in_life;
	if (!(proc = (t_proc*)malloc(sizeof(t_proc))))
		ft_errors("ERROR : Error malloc", 1, 0);
	proc->next = NULL;
	if (e->proc_start != NULL)
		proc->next = e->proc_start;
	e->proc_start = proc;
	if (e->verbose & VERBOSE_DEBUG)
		ft_printf("creation proc : %d -> cycle %d\n", e->nb_proc, e->nb_cycle);
	if (papa)
		copie_proc(proc, papa, pos, e);
	else
	{
		bzero(proc->r, REG_NUMBER);
		proc->r[0] = nb;
		proc->champ_color = -nb;
		proc->pos = pos;
		proc->wait_cycle = 0;
		proc->carry = 0;
		proc->live_exec = 0;
		init_proc(proc);
	}
	proc->index = e->nb_proc;
}
