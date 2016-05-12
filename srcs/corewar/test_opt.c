/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 19:18:01 by ale-naou          #+#    #+#             */
/*   Updated: 2016/05/12 19:29:37 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void		test_option(t_env *e, char *s)
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

int			test_param_opt(t_env *e, char *av)
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

void		show_start(t_env *e)
{
	int		i;
	t_champ *champ;

	champ = e->champ_start;
	i = 0;
	if (!have_opt('c', e->opt))
	{
		if (e->nb_champ > 0 && !have_opt('c', e->opt))
			ft_putendl("Introducing contestants...");
		while (++i <= e->nb_champ)
		{
			if (!have_opt('c', e->opt))
				printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				-champ->nb_champ, champ->width, champ->name, champ->comment);
			champ = champ->next;
		}
	}
}

void		last_check(t_env *e)
{
	if (e->nb_champ == 0)
		ft_errors("ERROR : no champ", 1, 0);
	if ((e->c > 0 && e->v > 0) || (e->c > 0 && e->d > 0))
		ft_errors("ERROR : error with param -v", 1, 0);
	if (e->n3 > 0 || e->c > 1 || e->d > 1 || e->v > 1)
		ft_errors("ERROR : bad syntax", 1, 0);
	show_start(e);
}
