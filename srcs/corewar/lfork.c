/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:17:51 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/05 15:00:57 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			lfork_cor(t_env *e, t_proc *proc)
{
	int		pos;
	int 	pos_new;

	pos = (proc->pc + (proc->inst.arg[0]));
	if ((pos_new = pos % MEM_SIZE) < 0)
		pos_new = MEM_SIZE - pos_new;
	new_processus(e, 0, pos_new, proc);
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d (%d)\n", proc->index, "fork", \
		proc->inst.arg[0], pos_new);
	return (1);
}
