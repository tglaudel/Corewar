/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:23:46 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/13 12:40:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			aff(t_env *e, t_proc *proc)
{
	(void)e;
	if (proc->inst.arg[0] > REG_NUMBER)
		return (0);
	if (e->verbose & VERBOSE_OP)
		printf("P %4d | %s r%d", proc->index, "aff", proc->inst.arg[0]);
	if (!have_opt('c', e->opt))
		printf("%c", e->mem[proc.inst[0]]);
	return (1);
}
