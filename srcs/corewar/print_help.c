/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:40:14 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/26 16:28:19 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			print_help(void)
{
	int		fd;
	char	*line;

	if ((fd = open("./ressources/template/help_cor.txt", O_RDONLY)) == -1)
		ft_errors("ERROR : Help file not found.", 1, 0);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
		line = NULL;
	}
	ft_strdel(&line);
	if (close(fd) == -1)
		ft_errors("ERROR : Close help.txt", 1, 0);
	return (0);
}
