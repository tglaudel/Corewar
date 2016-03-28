/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:30:41 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 17:02:09 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			invert(int n)
{
	unsigned char tmp1;
	unsigned char tmp2;
	unsigned char tmp3;
	unsigned char tmp4;

	tmp1 = n >> 24;
	tmp2 = n >> 16;
	tmp3 = n >> 8;
	tmp4 = n;
	n = tmp4 << 8;
	n = (n | tmp3) << 8;
	n = (n | tmp2) << 8;
	n = n | tmp1;
	return (n);
}

int			is_all_num(char *s)
{
	int i;
	int sign;

	i = 0;
	sign = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		sign++;
	}
	while (s[i] != '\0')
	{
		if (in_str(s[i], COMMENT_CHAR))
			break ;
		if (ft_isdigit(s[i]) != 1)
		{
			while (s[i] == ' ' || s[i] == '\t')
				i++;
			if (s[i] == '\0' || in_str(s[i], COMMENT_CHAR))
				return (1);
			return (0);
		}
		i++;
	}
	return (i >= 1 + sign);
}

int			len_tab(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			in_str(char c, char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

char		*format_str(char *s)
{
	int		i;
	int		n;
	char	*str;

	n = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	while (s[i + n] != '\t' && s[i + n] != ' ' && s[i + n] != '\0' &&\
	in_str(s[i + n], COMMENT_CHAR) != 1)
		n++;
	str = ft_strsub(&s[i], 0, n);
	return (str);
}
