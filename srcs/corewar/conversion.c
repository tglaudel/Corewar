/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:43:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 22:05:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

short int		dir_to_int(unsigned char *mem, int pos)
{
	short int dir;

	dir = 0;
	dir = mem[pos % MEM_SIZE] << 8;
	dir = dir | mem[(pos + 1) % MEM_SIZE];
	return (dir);
}

int				pre_int(t_proc *proc, unsigned char *mem, int n, int a)
{
	proc->inst.arg[a] = ind_to_int(mem, n);
	return (2);
}

int				ind_to_int(unsigned char *mem, int pos)
{
	int ind;

	ind = 0;
	ind = (ind | mem[pos % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 1) % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 2) % MEM_SIZE]) << 8;
	ind = ind | mem[(pos + 3) % MEM_SIZE];
	return (ind);
}
