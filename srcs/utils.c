/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:30:41 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 17:15:22 by tglaudel         ###   ########.fr       */
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
		sign++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) != 1)
			return (0);
		i++;
	}
	if (i >= 1 + sign)
		return (1);
	return (0);
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
