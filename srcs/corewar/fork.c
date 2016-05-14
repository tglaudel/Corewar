/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:56:20 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/14 10:49:26 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			fork_cor(t_env *e, t_proc *proc)
{
	int		pos;
	int		pos_new;

	pos = (proc->pos + (proc->inst.arg[0] % IDX_MOD));
	pos_new = pos;
	if ((pos = pos % MEM_SIZE) < 0)
		pos = MEM_SIZE + pos;
	new_processus(e, 0, pos, proc);
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d (%d)\n", proc->index, "fork", \
		proc->inst.arg[0], pos_new);
	return (1);
}
