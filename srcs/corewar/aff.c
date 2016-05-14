/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:23:46 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/14 11:14:04 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			aff(t_env *e, t_proc *proc)
{
	if (proc->inst.arg[0] > REG_NUMBER)
		return (0);
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s r%d \n", proc->index, "aff", proc->inst.arg[0]);
	if (!have_opt('c', e->opt))
		ft_printf("%c", e->mem[proc->inst.arg[0]] % 256);
	return (1);
}
