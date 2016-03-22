/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:50:47 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/22 15:51:17 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_errors(char *str, int i, int log)
{
	int			fd;

	fd = 2;
	if (log == 1)
		if ((fd = open("log", O_CREAT | O_RDWR | O_APPEND, 0644)) == -1)
			ft_putendl_fd("ERRORS : OPEN", 2);
	ft_putendl_fd(str, fd);
	fd != 2 ? ft_putendl_fd(str, 2) : 0;
	if (close(fd) == -1)
	{
		ft_putendl_fd("ERRORS : CLOSE", 2);
		exit(1);
	}
	i == 1 ? exit(1) : 0;
}
