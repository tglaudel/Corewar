/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:13:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/27 11:15:32 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int		check_octet(char *s)
{
	int fd;
	char buf[PROG_NAME_LENGTH + 12];
	int i;
	long int n;
	int ret;

	i = -1;
	n = 0;
	if ((fd = open(s, O_RDONLY)) == -1)
		ft_errors("ERROR : Fail open.", 0, 0);
	ret = read(fd, buf, PROG_NAME_LENGTH + 12);
	while (++i < 4)
	{
		n += (unsigned char)buf[PROG_NAME_LENGTH + 8 + i];
		n = n << 8;
	}
	close(fd);
	return ((int)(n >> 8));
}

int				is_champ(char *s)
{
	int i;
	int width;

	i = ft_strlen(s);
	if (ft_strcmp(".cor", &s[i - 4]))
		return (0);
	width = check_octet(s);
	if (width > CHAMP_MAX_SIZE || width == -1)
		return (0);
	return (width);
}
