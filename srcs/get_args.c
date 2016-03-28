/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:37:02 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 14:49:58 by tglaudel         ###   ########.fr       */
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
			ft_strdel(&line);
			ft_errors("ERROR : invalide line in .s", 1, 0);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

void		get_args(char **av, t_env *e)
{
	int		i;
	int		fd;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	while (av[i] && av[i][0] == '-')
		i++;
	if (av[i] == NULL)
		ft_errors("ERROR : No args.", 1, 0);
	else if (check_asm(av[i]) != 1)
		ft_errors("ERROR : format file.", 1, 0);
	else if ((fd = open(av[i], O_RDWR)) == -1)
		ft_errors("ERROR : Open file fail.", 1, 0);
	else if (check_args(fd, e) != 1)
		ft_errors("ERROR : format cmd.", 1, 0);
	while (av[i][j] != '.')
		j++;
	tmp = ft_strsub(av[i], 0, j);
	e->name = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
}
