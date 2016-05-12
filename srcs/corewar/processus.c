/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:01:32 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 14:35:51 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static void copie_proc(t_proc *new, t_proc *papa, int pos, t_env *e)
{
	int i;

	i = -1;
	(void)e;
	while (++i < REG_NUMBER)
		new->r[i] = papa->r[i];
	new->pos = pos;
	new->wait_cycle = 0;
	new->carry = papa->carry;
	new->live_exec = papa->live_exec;
	new->champ_color = papa->champ_color;
	new->inst.odc = 0;
	new->inst.size = 0;
	new->inst.opc = 0;
	ft_bzero(new->inst.arg, 4);
	new->exec = 0;
	new->pc = 0;
}

static int	*init_registre(void)
{
	int *r;
	int i;

	i = -1;
	r = (int*)malloc(sizeof(int) * REG_NUMBER);
	while (++i < REG_NUMBER)
		r[i] = 0;
	return (r);
}

void		new_processus(t_env *e, t_champ *champ, int pos, t_proc *papa)
{
	t_proc *proc;

	proc = NULL;
	++e->nb_proc;
	++e->nb_proc_in_life;
	if (!(proc = (t_proc*)malloc(sizeof(t_proc))))
		ft_errors("ERROR : Error malloc", 1, 0);
	proc->next = NULL;
	proc->r = init_registre();
	if (e->proc_start != NULL)
		proc->next = e->proc_start;
	e->proc_start = proc;
	if (e->verbose & VERBOSE_DEBUG)
		printf("creation proc : %d -> cycle %d\n", e->nb_proc, e->nb_cycle);
	if (papa)
		copie_proc(proc, papa, pos, e);
	else
	{
		ft_bzero(proc->r, REG_NUMBER);
		proc->r[0] = champ->nb_champ;
		proc->champ_color = champ->color;
		proc->pos = pos;
		proc->wait_cycle = 0;
		proc->carry = 0;
		proc->live_exec = 0;
		init_proc(proc);
	}
	proc->index = e->nb_proc;
}
