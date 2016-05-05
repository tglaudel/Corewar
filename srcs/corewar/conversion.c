/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:43:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/05 17:57:22 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

short int		dir_to_int(unsigned char *mem, int pos)
{
	short int dir;

	// ft_printf("%3.2x", mem[pos]);
	// ft_printf("%3.2x \n", mem[pos + 1]);
	dir = 0;
	dir = mem[pos] << 8;
	dir = dir | mem[(pos + 1) % MEM_SIZE];
	// ft_putnbr(dir);
	// ft_putchar('\n');
	return (dir);
}

int			ind_to_int(unsigned char *mem, int pos)
{
	int ind;

	// ft_printf("%3.2x", mem[pos]);
	// ft_printf("%3.2x", mem[pos + 1]);
	// ft_printf("%3.2x", mem[pos + 2]);
	// ft_printf("%3.2x \n", mem[pos + 3]);
	ind = 0;
	ind = (ind | mem[pos]) << 8;
	ind = (ind | mem[(pos + 1) % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 2) % MEM_SIZE]) << 8;
	ind = ind | mem[(pos + 3) % MEM_SIZE];
	return (ind);
}
