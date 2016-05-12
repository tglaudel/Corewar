/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:13:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 18:52:52 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static int			check_octet(char *s)
{
	int			i;
	long int	n;

	n = 0;
	i = -1;
	while (++i < 4)
	{
		n += (unsigned char)s[PROG_NAME_LENGTH + 8 + i];
		n = n << 8;
	}
	return ((int)(n >> 8));
}

static int			is_len_champ(t_env *e, int width)
{
	int		i;
	int		n;
	char	buf;
	int		ret;

	n = 0;
	i = 0;
	while ((ret = read(e->fd, &buf, 1)) == 1)
		n++;
	if (width != n || n > CHAMP_MAX_SIZE)
		return (-1);
	return (0);
}

static int			is_header_good(t_env *e)
{
	int		ret;
	int		i;
	int		n;
	char	buf[COMMENT_NAME_MAGIC];

	n = 0;
	i = -1;
	while (n < COMMENT_NAME_MAGIC)
	{
		if ((ret = read(e->fd, &buf[++i], 1)) == -1)
			return (-1);
		n++;
	}
	if (n != COMMENT_NAME_MAGIC ||
		(unsigned char)buf[1] != (unsigned char)(COREWAR_EXEC_MAGIC >> 16) ||
		(unsigned char)buf[2] != (unsigned char)(COREWAR_EXEC_MAGIC >> 8) ||
		(unsigned char)buf[3] != (unsigned char)(COREWAR_EXEC_MAGIC))
		return (-1);
	return (check_octet(buf));
}

int					is_champ(char *s, t_env *e)
{
	int i;

	if (e->test_n > 0)
		ft_errors("ERROR : Bad positionning -n", 1, 0);
	if (s == NULL)
		ft_errors("ERROR : error param for opt", 1, 0);
	if (s == NULL)
		return (-1);
	i = ft_strlen(s);
	if (ft_strcmp(".cor", &s[i - 4]))
		return (-1);
	if ((e->fd = open(s, O_RDONLY)) == -1)
		ft_errors("ERROR : Fail open.", 1, 0);
	if ((e->width = is_header_good(e)) < 0)
		return (-1);
	if (is_len_champ(e, e->width) == -1)
		return (-1);
	close(e->fd);
	(e->char_opt == 'n' || e->n3) > 0 ? e->n3-- : 0;
	e->char_opt != 'n' ? e->char_opt = '\0' : 0;
	return (0);
}
