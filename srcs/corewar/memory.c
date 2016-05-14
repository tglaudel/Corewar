/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:31:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 10:50:18 by tglaudel         ###   ########.fr       */
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
		ft_printf("0x%.4x : ", i);
		y = -1;
		while (++y < 64)
			ft_printf("%2.2x ", (unsigned char)s[i++]);
		ft_printf("\n");
	}
}

void				insert_in_memory(t_env *e)
{
	int		i;
	t_champ	*champ;
	int		n;

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
		n += MEM_SIZE / e->nb_champ;
		champ = champ->next;
	}
}
