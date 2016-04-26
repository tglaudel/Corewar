/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/26 19:03:16 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static void		insert_in_memory(t_env *e)
{
	int i;
	t_champ *tmp;
	int n;

	tmp = e->champ_start;
	while (tmp)
	{
		while (i < tmp->width)
			e->mem[n + i] = tmp->code[i];
		tmp = tmp->next;
	}
	// A FINIR !!
}

static void		add_to_champ_lst(t_env *env, int nb, int width, char *file)
{
	t_champ *tmp;
	char *s;

	if (!(tmp = (t_champ*)malloc(sizeof(t_champ))))
		ft_errors("ERROR : Error malloc", 1, 0);
	env->champ_start = tmp;
	tmp->reg[0] = nb;
	s = get_champ_file(file, width);
	tmp->width = width;
	tmp->name = ft_strsub(s, 4, PROG_NAME_LENGTH);
	ft_putendl(tmp->name);
	tmp->comment = ft_strsub(s, 12 + PROG_NAME_LENGTH, COMMENT_LENGTH);
	ft_putendl(tmp->comment);
	tmp->code = ft_strsub(s, COMMENT_NAME_MAGIC, width);
	ft_putendl(tmp->code);
	tmp->next = NULL;
	// VIRER LES DEBUGS.
}

static void		init_env(t_env *e)
{
	(void)e;
	e->champ_start = NULL;
	e->nb_player = 0;
}

static void		cor_init(t_env *e, char **av)
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

int				main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		print_help();
		ft_errors("ERROR : invalide arguments.", 1, 0);
	}
	e.opt = get_opt(&av[1], OPT_STRING);
	if (have_opt('h', e.opt))
		return (print_help());
	cor_init(&e, &av[1]);
}
