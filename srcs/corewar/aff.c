/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:23:46 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/05 13:36:40 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			aff(t_env *e, t_proc *proc)
{
	(void)e;
	if (proc->inst.arg[0] > REG_NUMBER)
		return (0);
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s r%d", proc->index, "aff", proc->inst.arg[0]);
	printf("%c", proc->pos);
	return (1);
}
