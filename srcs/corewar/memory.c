/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:31:37 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/29 15:38:42 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void				print_memory(t_env *e, char *s, t_proc *start)
{
	int x;
	int x2;
	int y2;
	int y;
	int i;
	char *s2;

	x = -1;
	x2 = 0;
	i = 0;
	(void)s;
	while (++x < 64)
	{
		y = -1;
		y2 = 0;
		while (++y < 64)
		{
			if (is_prog_pos(start, x, y))
			{
				s2 = ft_itoa_base((unsigned char)s[i], 16);
				mvwaddch(e->curse.principal, y2, x2, s2[0]);
				y2++;
				mvwaddch(e->curse.principal, y2, x2, s2[1]);
				y2++;
				i++;
				// ft_printf("{blue}%3.2x", (unsigned char)s[i++]);
				// ft_putstr("\033[0m");
			}
			else if (s[i] == '\0')
			{
				s2 = ft_itoa_base((unsigned char)s[i], 16);
				mvwaddch(e->curse.principal, y2, x2, s2[0]);
				y2++;
				mvwaddch(e->curse.principal, y2, x2, s2[1]);
				y2++;
				i++;
				// ft_printf("%3.2x", (unsigned char)s[i++]);
			}
			else
			{
				s2 = ft_itoa_base((unsigned char)s[i], 16);
				mvwaddch(e->curse.principal, y2, x2, s2[0]);
				y2++;
				mvwaddch(e->curse.principal, y2, x2, s2[1]);
				y2++;
				i++;
				// ft_printf("{red}%3.2x", (unsigned char)s[i++]);
				// ft_putstr("\033[0m");
			}
		}
		x2++;
		// ft_putchar('\n');
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
		new_processus(e, tmp->nb_champ, n);
		n += MEM_SIZE / e->nb_player;
		tmp = tmp->next;
	}
}
