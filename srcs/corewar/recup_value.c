/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 09:27:55 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 16:54:12 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int	check_args(t_proc *proc, int i, int n)
{
	if (((proc->inst.odc >> i) & IND_CODE) == IND_CODE)
		return (1);
	else if (((proc->inst.odc >> i) & DIR_CODE) == DIR_CODE)
		return (1);
	else if (((proc->inst.odc >> i) & REG_CODE) == REG_CODE)
	{
		if (proc->inst.arg[n] > 16 || proc->inst.arg[n] < 1)
			return (0);
	}
	return (1);
}

int	recup_value(unsigned char *mem, t_proc *proc, int i, int n)
{
	int val;

	val = 0;
	if (((proc->inst.odc >> i) & IND_CODE) == IND_CODE)
	{
		if (proc->inst.opc == 13)
			val = dir_to_int(mem, proc->inst.arg[n] + proc->pos);
		else
			val = ind_to_int(mem, proc->inst.arg[n] + proc->pos);
	}
	else if (((proc->inst.odc >> i) & DIR_CODE) == DIR_CODE)
		val = proc->inst.arg[n];
	else
		val = proc->r[proc->inst.arg[n] - 1];
	return (val);
}
