/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 09:27:55 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/05 09:28:04 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int	recup_value(unsigned char *mem, t_proc *proc, int i, int n)
{
	int val;

	val = 0;
	if (((proc->inst.odc >> i) & IND_CODE) == IND_CODE)
		val = ind_to_int(mem, proc->inst.arg[n]);
	else if (((proc->inst.odc >> i) & DIR_CODE) == DIR_CODE)
		val = proc->inst.arg[n];
	else
		val = proc->r[proc->inst.arg[n] - 1];
	return (val);
}
