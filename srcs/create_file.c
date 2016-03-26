/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 18:16:36 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/26 18:54:36 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		create_file(t_header *cor, t_cmd *cmd, t_env *e)
{
	t_cmd *tmp;
	int fd;
	int i;

	tmp = cmd;
	ft_putstr(e->name);
	if ((fd = open("test.cor", O_CREAT | O_RDWR, 0664)) == -1)
		ft_errors("ERROR : Files .cor not create.", 1, 0);
	ft_putchar_fd(cor->magic >> 24, fd);
	ft_putchar_fd(cor->magic >> 16, fd);
	ft_putchar_fd(cor->magic >> 8, fd);
	ft_putchar_fd(cor->magic, fd);
	ft_putstr_fd(cor->prog_name, fd);
	ft_putchar_fd(cor->prog_size >> 24, fd);
	ft_putchar_fd(cor->prog_size >> 16, fd);
	ft_putchar_fd(cor->prog_size >> 8, fd);
	ft_putchar_fd(cor->prog_size, fd);
	ft_putstr_fd(cor->comment, fd);
	while (tmp)
	{
		i = -1;
		while (++i < tmp->size)
			ft_putchar_fd(tmp->octet[i], fd);
		tmp = tmp->next;
	}
}
