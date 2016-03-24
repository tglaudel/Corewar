/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:30:41 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/24 11:54:50 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
