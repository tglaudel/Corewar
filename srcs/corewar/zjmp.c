/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:42:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/03 14:32:08 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		zjmp(t_env *e, t_proc *proc)
{
	int tmp;

	tmp = proc->pos;
	if (proc->carry == 1) // si test enlever le carry c'est plutot pas mal, pd
	{
		tmp = (short int)proc->inst.arg[0];
		proc->pos += tmp;
		proc->pos = proc->pos % MEM_SIZE;
		if (proc->pos < 0)
			proc->pc = MEM_SIZE - proc->pos;
		else
			proc->pc = proc->pos;
		if (e->verbose & VERBOSE_OP)
			ft_printf("P %4d | %s %d OK\n", proc->index, "zjmp", tmp);
		return (1);
	}
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d FAILED\n", proc->index, "zjmp", tmp);
	return (0);
}
