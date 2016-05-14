/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:02 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 10:00:31 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_asm(char *s)
{
	int i;

	i = ft_strlen(s);
	if (s[i - 2] == '.' && s[i - 1] == 's')
		return (1);
	return (0);
}

static int	check_args(int fd, t_env *env)
{
	char *line;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strcmp(line, "\0") != 0 && \
		is_good_format(line, &env->cor, env) != 1)
		{
			ft_putendl(line);
			free(line);
			line = NULL;
			ft_errors("ERROR : invalide line in .s", 1, 0);
		}
		free(line);
		line = NULL;
	}
	return (1);
}

int			get_args(char *av, t_env *e)
{
	int		fd;
	int		j;
	char	*tmp;

	j = 0;
	if (av && av[0] == '-')
		return (1);
	if (av == NULL || check_asm(av) != 1 || (fd = open(av, O_RDWR)) == -1)
		ft_errors("ERROR : No args/file or bad format file.", 1, 0);
	else if (check_args(fd, e) != 1)
		ft_errors("ERROR : bad format cmd.", 1, 0);
	av[j] == '.' ? j++ : 0;
	while (av[j] != '.')
		j++;
	tmp = ft_strsub(av, 0, j);
	e->name = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
	return (1);
}
