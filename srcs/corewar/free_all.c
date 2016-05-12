/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 11:05:25 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 18:56:26 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static void	free_champ(t_champ *start)
{
	t_champ *champ;
	t_champ *champ_next;

	champ = start;
	while (champ)
	{
		champ_next = champ->next;
		ft_strdel(&champ->name);
		ft_strdel(&champ->comment);
		ft_strdel(&champ->code);
		free(champ);
		champ = NULL;
		champ = champ_next;
	}
}

void		free_all(t_env *e)
{
	if (e->winner.winner)
		e->winner.winner = NULL;
	free_champ(e->champ_start);
}
