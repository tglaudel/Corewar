/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:43:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/11 09:27:22 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

short int		dir_to_int(unsigned char *mem, int pos)
{
	short int dir;

	// printf("%3.2x", mem[pos]);
	// printf("%3.2x \n", mem[pos + 1]);
	dir = 0;
	dir = mem[pos % MEM_SIZE] << 8;
	dir = dir | mem[(pos + 1) % MEM_SIZE];
	// ft_putnbr(dir);
	// ft_putchar('\n');
	return (dir);
}

int			ind_to_int(unsigned char *mem, int pos)
{
	int ind;

	// printf("%3.2x", mem[pos]);
	// printf("%3.2x", mem[pos + 1]);
	// printf("%3.2x", mem[pos + 2]);
	// printf("%3.2x \n", mem[pos + 3]);
	ind = 0;
	ind = (ind | mem[pos % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 1) % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 2) % MEM_SIZE]) << 8;
	ind = ind | mem[(pos + 3) % MEM_SIZE];
	return (ind);
}
