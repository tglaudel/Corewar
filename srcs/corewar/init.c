/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:59:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 19:28:28 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void			re_init_proc(t_proc *start)
{
	t_proc *proc;

	proc = start;
	while (proc)
	{
		proc->live_exec = 0;
		proc = proc->next;
	}
}

void			init_proc(t_proc *proc)
{
	proc->pc = 0;
	proc->inst.opc = 0;
	proc->inst.odc = 0;
	proc->inst.arg[0] = 0;
	proc->inst.arg[1] = 0;
	proc->inst.arg[2] = 0;
	proc->inst.size = 0;
	proc->exec = 0;
	proc->pc = 0;
}

static void		init_env2(t_env *e)
{
	e->c = 0;
	e->n3 = 0;
	e->d = 0;
	e->v = 0;
	e->test_n = 0;
	e->winner.winner = NULL;
	e->winner.nb_win = 0;
	ft_bzero(e->mem, MEM_SIZE + 1);
	ft_bzero(e->col, MEM_SIZE + 1);
}

void			init_env(t_env *e)
{
	e->champ_start = NULL;
	e->champ_end = NULL;
	e->proc_start = NULL;
	if (e->nb_cycle_max == -1)
		e->nb_cycle_max = 2147483647;
	e->nb_cycle = 0;
	e->nb_champ = 0;
	e->width = 0;
	e->c_to_die = CYCLE_TO_DIE;
	e->nb_proc = 0;
	e->nb_check_td = 0;
	e->global_live = 0;
	e->nb_proc_in_life = 0;
	e->speed = 10000;
	e->speed_mult = 0;
	e->iplayer = 0;
	e->player = NULL;
	e->char_opt = '\0';
	init_env2(e);
}

void			init_cor(t_env *e, char **av)
{
	int i;

	i = 0;
	init_env(e);
	while (av[i])
	{
		test_option(e, av[i]);
		if (ft_strcmp(av[i], "-c") != 0 && e->char_opt != '\0')
		{
			i++;
			if (test_param_opt(e, av[i]) == 1)
				i++;
		}
		else if (av[i] != NULL && ft_strcmp(av[i], "-c") != 0 &&
			is_champ(av[i], e) != -1)
		{
			++e->nb_champ > 4 ? ft_errors("ERROR : Nb champs > 4.", 1, 0) : 0;
			add_to_champ_lst(e, e->nb_champ, e->width, av[i]);
		}
		else if (av[i] != NULL && ft_strcmp("-c", av[i]) != 0)
			ft_errors("ERROR : option ./corewar -h for help", 1, 0);
		av[i] != NULL ? i++ : 0;
	}
	last_check(e);
	insert_in_memory(e);
}
