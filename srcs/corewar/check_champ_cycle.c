/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champ_cycle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 19:18:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/07 19:45:54 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void		check_champ_cycle(t_env *e)
{
	t_champ *champ;

	champ = e->champ_start;
	while (champ)
	{
		if (champ->is_alive)
		{
			if (champ->nb_live == 0)
			{
				champ->is_alive = 0;
				--e->nb_champ;
			}
			champ->nb_live = 0;
		}
		champ = champ->next;
	}
}
