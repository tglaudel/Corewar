/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:16:36 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/27 16:06:35 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		create_file(t_header *cor, t_cmd *cmd, t_env *e)
{
	t_cmd *tmp;
	int fd;
	int i;

	tmp = cmd;
	(void)e;
	(void)cor;
	if ((fd = open("test.cor", O_CREAT | O_RDWR, 0664)) == -1)
		ft_errors("ERROR : Files .cor not create.", 1, 0);
	cor->prog_size = invert(e->pos_rel);
	write(fd, cor, PROG_NAME_LENGTH + COMMENT_LENGTH + 2 + 8);
	write(fd, "\0\0\0\0\0\0", 6);
	while (tmp)
	{
		i = -1;
		while (++i < tmp->size)
			ft_putchar_fd(tmp->octet[i], fd);
		tmp = tmp->next;
	}
}
