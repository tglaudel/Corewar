/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:30:30 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/13 19:41:17 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ret_line(char **line, char **tmp, int fd, char *el)
{
	char		*del;

	if (!el)
	{
		*line = ft_strdup(tmp[fd]);
		ft_strdel(&tmp[fd]);
	}
	else
	{
		del = tmp[fd];
		*line = ft_strsub(tmp[fd], 0, el - tmp[fd]);
		tmp[fd] = ft_strsub(tmp[fd], el - tmp[fd] + 1,
				ft_strlen(el));
		ft_strdel(&del);
	}
}

int			get_next_line(int const fd, char **line)
{
	static char	*tmp[256];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*del;
	char		*el;

	ret = 0;
	if (fd < 0 || BUFF_SIZE < 1 || fd > 256 || !line)
		return (-1);
	if (!(tmp[fd] = tmp[fd] == NULL ? ft_strnew(1) : tmp[fd]))
		return (-1);
	while (!(el = ft_strchr(tmp[fd], '\n')) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		del = tmp[fd];
		buf[ret] = '\0';
		if (!(tmp[fd] = ft_strjoin(tmp[fd], buf)))
			return (-1);
		ft_strdel(&del);
	}
	if (ret == -1)
		return (-1);
	ret_line(line, tmp, fd, el);
	return (!tmp[fd] && ft_strlen(*line) == 0 ? 0 : 1);
}
