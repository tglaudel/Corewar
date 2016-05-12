/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:45:02 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/12 18:44:19 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		ldi(t_env *e, t_proc *proc)
{
	int val1;
	int val2;
	int pos;
	int pos_in_mem;

	if (!check_args(proc, 6, 0) || !check_args(proc, 4, 1))
		return (0);
	if (proc->inst.arg[2] > REG_NUMBER || proc->inst.arg[2] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 6, 0);
	val2 = recup_value(e->mem, proc, 4, 1);
	pos = (val1 + val2) % IDX_MOD;
	pos = (pos + proc->pos) % MEM_SIZE;
	pos_in_mem = pos;
	if (pos < 0)
		pos = MEM_SIZE + pos;
	proc->r[proc->inst.arg[2] - 1] = ind_to_int(e->mem, pos);
	if (e->verbose & VERBOSE_OP)
	{
		printf("P %4d | %s %d %d r%d\n", proc->index, "ldi",\
		val1, val2, proc->inst.arg[2]);
		printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",\
		val1, val2, val1 + val2, pos_in_mem);
	}
	return (1);
}
