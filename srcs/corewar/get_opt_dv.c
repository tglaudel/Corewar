/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt_dv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 19:09:05 by ale-naou          #+#    #+#             */
/*   Updated: 2016/05/12 19:10:31 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

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
