/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:40:14 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 14:27:12 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			print_help(void)
{
	int		fd;
	char	*line;

	if ((fd = open("./ressources/template/help.txt", O_RDONLY)) == -1)
		ft_errors("ERROR : Help file not found.", 1, 0);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
		line = NULL;
	}
	ft_strdel(&line);
	return (0);
}
