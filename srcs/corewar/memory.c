/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:31:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/27 20:19:22 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void				print_memory(char *s)
{
	int x;
	int y;
	int i;

	x = -1;
	i = 0;
	(void)s;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			if (s[i] == '\0')
				ft_printf("%3.2x", (unsigned char)s[i++]);
			else
			{
				ft_printf("{red}%3.2x", (unsigned char)s[i++]);
				ft_putstr("\033[0m");
			}
		}
		ft_putchar('\n');
	}
}

void				insert_in_memory(t_env *e)
{
	int i;
	t_champ *tmp;
	int n;

	n = 0;
	tmp = e->champ_start;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->width)
			e->mem[n + i] = tmp->code[i];
		n += MEM_SIZE / e->nb_player;
		tmp = tmp->next;
	}
	print_memory(e->mem);
}
