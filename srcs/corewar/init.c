/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:59:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/30 13:43:47 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void		init_env(t_env *e)
{
	e->champ_start = NULL;
	e->champ_end = NULL;
	e->proc_start = NULL;
	if (e->nb_cycle_max == -1)
		e->nb_cycle_max = 2147483647;
	e->nb_player = 0;
	e->champ_in_life = 4;
	e->proc_in_life = 4;
	e->nb_proc = 0;
	bzero(e->mem, MEM_SIZE + 1);
}

void		init_cor(t_env *e, char **av)
{
	int i;
	int nb;
	int width;

	nb = 0;
	i = -1;
	init_env(e);
	while (av[++i])
		if ((width = is_champ(av[i])) > 0)
		{
			nb++;
			if (nb > 4)
				ft_errors("ERROR : Nb champs > 4.", 1, 0);
			add_to_champ_lst(e, nb, width, av[i]);
		}
	e->nb_player = nb;
	insert_in_memory(e);
}
