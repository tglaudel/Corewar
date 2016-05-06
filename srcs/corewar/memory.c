/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:31:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/06 17:02:42 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void				print_memory(t_env *e, unsigned char *s, t_proc *start)
{
	int x;
	int y;
	int i;

	x = -1;
	i = 0;
	(void)e;
	while (++x < 64)
	{
		y = -1;
		while (++y < 64)
		{
			if (is_prog_pos(start, x, y))
			{
				ft_printf("{blue}%3.2x", (unsigned char)s[i++]);
				ft_putstr("\033[0m");
			}
			else if (s[i] == '\0')
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
			e->col[n + i] = -champ->nb_champ;
		}
		new_processus(e, champ->nb_champ, n, NULL);
		//first_print(e, champ->nb_champ, n, champ->width);
		n += MEM_SIZE / e->nb_champ;
		champ = champ->next;
	}
}
