/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:43:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 18:55:17 by ale-naou         ###   ########.fr       */
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
