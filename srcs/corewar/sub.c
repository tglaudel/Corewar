/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:24:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/04 17:41:47 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int sub(t_env *e, t_proc *proc)
{
	int i;
	unsigned int d;

	(void)e;
	i = -1;
	while (++i < 3)
		if (proc->inst.arg[i] > REG_NUMBER || proc->inst.arg[i] == 0)
			return (0);
	d = (proc->r[proc->inst.arg[0] - 1] - proc->r[proc->inst.arg[1] - 1]) % MUI;
	proc->r[proc->inst.arg[2] - 1] = d;
	if (d == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s r%d r%d r%d\n", proc->index, "sub",\
		proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2]);
	return (1);
}
