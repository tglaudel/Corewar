/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:42:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/13 10:57:27 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		zjmp(t_env *e, t_proc *proc)
{
	int tmp;

	tmp = (short int)proc->inst.arg[0];
	if (proc->carry == 1)
	{
		mvchgat(proc->pos / 64 + 2, proc->pos % 64 * 3 + 6, 2, A_NORMAL,
				proc->champ_color, NULL);
		proc->pos = proc->pos + (tmp % IDX_MOD);
		proc->pos = proc->pos % MEM_SIZE;
		if (proc->pos < 0)
			proc->pc = MEM_SIZE + proc->pos;
		else
			proc->pc = proc->pos;
		if (e->verbose & VERBOSE_OP)
			printf("P %4d | %s %d OK\n", proc->index, "zjmp", tmp);
		return (1);
	}
	if (e->verbose & VERBOSE_OP)
		printf("P %4d | %s %d FAILED\n", proc->index, "zjmp", tmp);
	if (e->verbose & VERBOSE_PC)
		print_adv(proc, e, 0);
	return (0);
}
