/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:30:30 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/11 11:07:10 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnotnull(char *buf, char *str)
{
	char *tmp;

	tmp = str;
	str = ft_strjoin(tmp, buf);
	free(tmp);
	return (str);
}

char	*ft_strnext(char *str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	i = ft_strchr(str, '\n') - str;
	*line = ft_strsub(str, 0, i);
	tmp = str;
	str = ft_strsub(tmp, i + 1, ft_strlen(tmp) - i + 1);
	free(tmp);
	return (str);
}

t_fd	*ft_createstruct(int fd, t_fd *stru)
{
	int		i;
	t_fd	*tmp;

	tmp = stru;
	i = 0;
	if (tmp == NULL)
	{
		tmp = (t_fd*)malloc(sizeof(tmp) * 50);
		while (i < 50)
		{
			tmp[i].fd = -1;
			i++;
		}
	}
	i = 0;
	while (tmp[i].fd != -1)
	{
		if (tmp[i].fd == fd)
			return (tmp);
		i++;
	}
	tmp[i].fd = fd;
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	static t_fd	*stru = NULL;
	char		buf[BUFF_SIZE + 1];
	int			r[2];

	r[1] = 0;
	stru = ft_createstruct(fd, stru);
	while (stru[r[1]].fd != fd)
		r[1]++;
	while (stru[r[1]].str == NULL || ft_strchr(stru[r[1]].str, '\n') == NULL)
	{
		r[0] = read(fd, buf, BUFF_SIZE);
		buf[r[0]] = '\0';
		if (r[0] < 0 || line == NULL)
			return (-1);
		if (r[0] == 0 && stru[r[1]].str != NULL)
		{
			*line = ft_strdup(stru[r[1]].str);
			ft_strdel(&stru[r[1]].str);
			return (ft_strcmp(*line, "") != 0);
		}
		stru[r[1]].str = (stru[r[1]].str != NULL) ? (ft_strnotnull(buf, \
					stru[r[1]].str)) : (ft_strdup(buf));
	}
	stru[r[1]].str = ft_strnext(stru[r[1]].str, line);
	return (1);
}
