/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:59:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 12:24:58 by fgiraud          ###   ########.fr       */
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

void			init_env(t_env *e)
{
	e->champ_start = NULL;
	e->champ_end = NULL;
	e->proc_start = NULL;
	if (e->nb_cycle_max == -1)
		e->nb_cycle_max = 2147483647;
	e->nb_cycle = 0;
	e->nb_champ = 0;
	e->c_to_die = CYCLE_TO_DIE;
	e->nb_proc = 0;
	e->nb_check_td = 0;
	e->global_live = 0;
	e->nb_proc_in_life = 0;
	e->speed = 10000;
	e->speed_mult = 0;
	bzero(e->mem, MEM_SIZE + 1);
	bzero(e->col, MEM_SIZE + 1);
	e->iplayer = 0;
	e->player = NULL;
	e->char_opt = '\0';
	e->c = 0;
	e->n3 = 0;
	e->d = 0;
	e->v = 0;
	e->test_n = 0;
}

static void		test_option(char *s, t_env *e)
{
	if (e->n3 > 1)
		ft_errors("ERROR : error opt -n", 1, 0);
	if (ft_strcmp(s, "-n") == 0)
	{
		e->n3++;
		e->char_opt = 'n';
	}
	else if (ft_strcmp(s, "-v") == 0)
	{
		e->n3 > 0 ? e->test_n++ : 0;
		e->v++;
		e->char_opt = 'v';
	}
	else if (ft_strcmp(s, "-d") == 0)
	{
		e->n3 > 0 ? e->test_n++ : 0;
		e->d++;
		e->char_opt = 'd';
	}
	else if (ft_strcmp(s, "-c") == 0)
	{
		e->n3 > 0 ? e->test_n++ : 0;
		e->c++;
	}
}

static int		test_param_opt(t_env *e, char *av)
{
	int i;
	int i2;

	i = 0;
	if (av == NULL)
		ft_errors("ERROR : bad positionning opt", 1, 0);
	i2 = ft_strlen(av);
	av[0] == '-' ? i++ : 0;
	while (av[i] != '\0')
	{
		if (ft_isdigit(av[i]) == 0)
			ft_errors("ERROR : val param option", 1, 0);
		i++;
	}
	if (ft_atod(av) > 2147483647 || ft_atod(av) < -2147483648)
		ft_errors("ERROR : val param opt", 1, 0);
	e->char_opt == '\0' ? ft_errors("ERROR : val with no param", 1, 0) : 0;
	(e->char_opt != 'v' || e->char_opt != 'd') ? e->char_opt = '\0' : 0;
	e->player = av;
	return (0);
}

static void		show_start(t_env *e)
{
	int		i;
	t_champ *champ;

	champ = e->champ_start;
	i = 0;
	if (e->nb_champ > 0 && !have_opt('c', e->opt))
		ft_putendl("Introducing contestants...");
	while (++i <= e->nb_champ)
	{
		if (!have_opt('c', e->opt))
			printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			champ->nb_champ, e->width, champ->name, champ->comment);
		champ = champ->next;
	}
}

static void		last_check(t_env *e)
{
	if (e->nb_champ == 0)
		ft_errors("ERROR : no champ", 1, 0);
	if ((e->c > 0 && e->v > 0) || (e->c > 0 && e->d > 0))
		ft_errors("ERROR : error with param -v", 1, 0);
	if (e->n3 > 0 || e->c > 1 || e->d > 1 || e->v > 1)
		ft_errors("ERROR : bad syntax", 1, 0);
	show_start(e);
}

void			init_cor(t_env *e, char **av)
{
	int i;

	i = 0;
	init_env(e);
	while (av[i])
	{
		test_option(av[i], e);
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
