/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 12:59:51 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/19 19:48:41 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include "libft.h"
# include <fcntl.h>

typedef struct	s_fd
{
	char		*str;
	int			fd;
}				t_fd;

int				get_next_line(int fd, char **line);

#endif
