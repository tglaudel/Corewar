/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:05:10 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/04 16:06:34 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

// st : Prend un registre et un registre ou un indirect, et stocke la valeur du registre
// vers le second paramètre. Son opcode est 0x03. Par exemple, st r1, 42 stocke la
// valeur de r1 à l’adresse (PC + (42 % IDX_MOD))

int		st(t_env *e, t_proc *proc)
{
	int pos;

	if (proc->inst.arg[0] > REG_NUMBER || proc->inst.arg[0] == 0)
		return (0);
	if (((proc->inst.odc >> 4) & IND_CODE) == IND_CODE)
	{
		pos = proc->pc + proc->inst.arg[1] % IDX_MOD;
		pos = pos % MEM_SIZE;
		if (pos < 0)
			pos = MEM_SIZE - pos;
		print_in_memory(e->mem, proc->r[proc->inst.arg[0] - 1], pos);
	}
	else
	{
		if (proc->inst.arg[1] > REG_NUMBER || proc->inst.arg[1] == 0)
			return (0);
		proc->r[proc->inst.arg[1] - 1] = proc->r[proc->inst.arg[0] - 1];
	}
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s r%d %d\n", proc->index, "st",\
		proc->inst.arg[0], proc->inst.arg[1]);
	return (1);
}
