/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:41:53 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/02 19:02:53 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		live(t_env *e, t_proc *proc) // ca a l'air ok
{
	t_champ *champ;

	++proc->live_exec;
	champ = e->champ_start;
	while (champ)
	{
		if (champ->nb_champ == (int)proc->inst.arg[0])
		{
			++champ->nb_live;
			++e->global_live;
			ft_printf("%d -> live %d\n", champ->nb_champ, champ->nb_live);
			return (1);
		}
		champ = champ->next;
	}
	return (0);
}
