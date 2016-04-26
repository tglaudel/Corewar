/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:52:24 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/26 18:54:00 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

char		*get_champ_file(char *file, int width)
{
	int fd;
	char buf[COMMENT_NAME_MAGIC + width];
	int i;
	int ret;
	char *s;


	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_errors("ERROR : Fail open.", 1, 0);
	ret = read(fd, buf, COMMENT_NAME_MAGIC + width);
	if (!(s = (char*)malloc(sizeof(char) * COMMENT_NAME_MAGIC + width)))
		ft_errors("ERROR : malloc.", 1, 0);
	while (++i <= COMMENT_NAME_MAGIC + width)
	{
		//ft_printf("%d -> %x -> %c \n", i, (unsigned char)buf[i], buf[i]);
		s[i] = buf[i];
	}
	return (s);
}
