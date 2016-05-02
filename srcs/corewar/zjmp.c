/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:42:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/02 21:46:09 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		zjmp(t_env *e, t_proc *proc)
{
	(void)e;
	if (proc->carry == 1) // si test enlever le carry c'est plutot pas mal, pd
	{
		proc->pos += ((int)proc->inst.arg[0] - 1)% MEM_SIZE;
		if (proc->pos < 0)
			proc->pos = MEM_SIZE + proc->pos;
		proc->pc = proc->pos;
		return (1);
	}
	return (0);
}
