/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:07:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/12 17:58:01 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		lld(t_env *e, t_proc *proc)
{
	int val1;

	if (proc->inst.arg[1] > REG_NUMBER || proc->inst.arg[1] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 6, 0);
	if (val1 == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	proc->r[proc->inst.arg[1] - 1] = val1;
	if (e->verbose & VERBOSE_OP)
		printf("P %4d | %s %d r%d\n", proc->index, "lld",\
		val1, proc->inst.arg[1]);
	return (1);
}
