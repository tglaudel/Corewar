/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:13:48 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/11 14:49:21 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int		add_opt(int pos, int opt)
{
	int		tmp;

	if (pos == -1)
		ft_errors("ERROR : Illegal option.", 1, 0);
	tmp = 1;
	tmp = tmp << pos;
	opt = opt | tmp;
	return (opt);
}

static int		position_in_opt(char *opt, char o)
{
	int		i;

	i = -1;
	while (opt[++i])
	{
		if (o == opt[i])
			return (i);
	}
	return (-1);
}

int				have_opt(char o, int opt)
{
	int tmp;
	int i;

	tmp = 1;
	i = position_in_opt(OPT_STRING, o);
	tmp = tmp << i;
	if (tmp & opt)
		return (1);
	return (0);
}

int				get_verbose(char **av)
{
	int		i;

	i = -1;
	while (av[++i])
		if (av[i][0] == '-' && av[i][1] == 'v' && av[i][2] == '\0')
			return (ft_atoi(av[i + 1]));
	return (0);
}

int				get_ncycle(char **av)
{
	int		i;

	i = -1;
	while (av[++i])
		if (av[i][0] == '-' && av[i][1] == 'd' && av[i][2] == '\0')
			return (ft_atoi(av[i + 1]));
	return (-1);
}

int				get_opt(char **av, char *l_opt)
{
	int		opt;
	int		i;
	int		j;

	i = -1;
	opt = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] == '-' && av[i][1] != '\0' && !ft_isdigit(av[i][1]))
		{
			while (av[i][++j])
				opt = add_opt(position_in_opt(l_opt, av[i][j]), opt);
		}
	}
	return (opt);
}
