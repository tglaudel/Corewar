/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:41:53 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/12 12:28:45 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		live(t_env *e, t_proc *proc)
{
	t_champ *champ;

	champ = e->champ_start;
	proc->live_exec = 0;
	++e->global_live;
	if (e->verbose & VERBOSE_OP)
		print_instruction(proc, 1, "live", 0);
	while (champ)
	{
		if (champ->nb_champ == (int)proc->inst.arg[0])
		{
			if (champ->is_alive)
			{
				++champ->nb_live;
				champ->last_cycle_live = e->nb_cycle;
				e->winner.winner = champ->name;
				e->winner.nb_win = champ->nb_champ;
			}

			if (e->verbose & VERBOSE_LIVE)
				printf("Player %d (%s) is said to be alive\n", -champ->nb_champ, champ->name);
			return (1);
		}
		champ = champ->next;
	}
	return (0);
}
