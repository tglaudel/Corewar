/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:31:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 14:33:24 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void				print_memory(unsigned char *s)
{
	int x;
	int y;
	int i;

	x = -1;
	i = 0;
	while (++x < 64)
	{
		printf("0x%.4x : ", i);
		y = -1;
		while (++y < 64)
			printf("%2.2x ", (unsigned char)s[i++]);
		printf("\n");
	}
}

void				insert_in_memory(t_env *e)
{
	int i;
	t_champ *champ;
	int n;

	n = 0;
	champ = e->champ_start;
	while (champ)
	{
		i = -1;
		champ->pos = n;
		while (++i < champ->width)
		{
			e->mem[n + i] = champ->code[i];
			e->col[n + i] = champ->color;
		}
		new_processus(e, champ, n, NULL);
		//first_print(e, champ->nb_champ, n, champ->width);
		n += MEM_SIZE / e->nb_champ;
		champ = champ->next;
	}
}
