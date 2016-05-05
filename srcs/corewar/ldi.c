/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:45:02 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/05 09:29:18 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

// ldi : Au lieu de ça, ca prend 2 index et 1 registre, additionne les 2 premiers,
// traite ca comme une adresse, y lit une valeur de la taille d’un registre et
// la met dans le 3eme.

int ldi(t_env *e, t_proc *proc)
{
	int val1;
	int val2;
	int pos;

	if (proc->inst.arg[2] > REG_NUMBER || proc->inst.arg[2] <= 0)
		return (0);
	val1 = recup_value(e->mem, proc, 6, 0);
	val2 = recup_value(e->mem, proc, 4, 1);
	pos = (val1 + val2) % MEM_SIZE;
	if (pos < 0)
		pos = MEM_SIZE - pos;
	proc->inst.arg[2] = ind_to_int(e->mem, pos);
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d %d r%d\n", proc->index, "ldi",\
		val1, val2, proc->inst.arg[2]);
	return (1);
}
