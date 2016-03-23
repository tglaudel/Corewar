/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:02 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 15:03:36 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_asm(char *s)
{
	int i;

	i = ft_strlen(s);
	if (s[i - 2] != '.' && s[i - 1] != 's')
		return (0);
	return (1);
}

static int	check_args(int fd, t_env *env)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (is_good_format(line, &env->cor, env))
		{
			continue ;
			//ft_putendl(line);
			//add_args(line, env);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

void		get_args(char **av, t_env *e)
{
	int i;
	int fd;

	i = 0;
	(void)e;
	while (av[i] && av[i][0] == '-')
		i++;
	if (check_asm(av[i]) != 1)
		ft_errors("ERROR : format file.", 1, 0);
	if ((fd = open(av[i], O_RDONLY)) == -1)
		ft_errors("ERROR : Open file fail.", 1, 0);
	if (check_args(fd, e) != 1)
		ft_errors("ERROR : format cmd.", 1, 0);
}
