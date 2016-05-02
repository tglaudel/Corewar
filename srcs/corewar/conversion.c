/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:43:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/02 19:00:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

unsigned int			dir_to_int(unsigned char *mem, int pos)
{
	unsigned int dir;

	ft_printf("%3.2x", mem[pos]);
	ft_printf("%3.2x \n", mem[pos + 1]);
	dir = 0;
	dir = (dir | mem[pos]) << 8;
	dir = dir | mem[(pos + 1) % MEM_SIZE];

	return (dir);
}

unsigned int			ind_to_int(unsigned char *mem, int pos)
{
	unsigned int ind;

	ft_printf("%3.2x", mem[pos]);
	ft_printf("%3.2x", mem[pos + 1]);
	ft_printf("%3.2x", mem[pos + 2]);
	ft_printf("%3.2x \n", mem[pos + 3]);
	ind = 0;
	ind = (ind | mem[pos]) << 8;
	ind = (ind | mem[(pos + 1) % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 2) % MEM_SIZE]) << 8;
	ind = ind | mem[(pos + 3) % MEM_SIZE];
	return (ind);
}
