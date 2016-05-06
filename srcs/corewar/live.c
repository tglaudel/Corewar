/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:41:53 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/06 12:04:20 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		live(t_env *e, t_proc *proc) // ca a l'air ok
{
	t_champ *champ;

	++proc->live_exec;
	champ = e->champ_start;
	if (e->verbose & VERBOSE_OP)
		ft_printf("P %4d | %s %d\n", proc->index, "live", proc->inst.arg[0]);
	while (champ)
	{
		if (champ->nb_champ == (int)proc->inst.arg[0])
		{
			++champ->nb_live;
			++e->global_live;
			champ->last_cycle_live = e->nb_cycle;
			if (e->verbose & VERBOSE_LIVE)
				ft_printf("Player %d (%s) is said to be alive\n", -champ->nb_champ, champ->name);
			return (1);
		}
		champ = champ->next;
	}
	return (0);
}
