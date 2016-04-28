/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:01:32 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/28 22:10:22 by tglaudel         ###   ########.fr       */
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

void		new_processus(t_env *e, int nb, int pos)
{
	t_proc *tmp;

	++e->nb_proc;
	if (!(tmp = (t_proc*)malloc(sizeof(t_proc))))
		ft_errors("ERROR : Error malloc", 1, 0);
	tmp->next = NULL;
	if (e->proc_start != NULL)
		tmp->next = e->proc_start;
	e->proc_start = tmp;
	bzero(tmp->r, REG_NUMBER);
	tmp->r[0] = nb;
	tmp->pos = pos;
	tmp->index = e->nb_proc;
	tmp->inst.arg = (unsigned int*)malloc(sizeof(unsigned int) * 3);
	tmp->inst.opc = 0;
	tmp->inst.odc = 0;
	tmp->inst.arg[0] = 0;
	tmp->inst.arg[1] = 0;
	tmp->inst.arg[2] = 0;
}
