/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:24:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 19:41:13 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_ind(char *s)
{
	if (is_all_num(&s[0]) == 1)
		return (1);
	return (0);
}

int		is_reg(char *s)
{
	if (s[0] == 'r' && is_all_num(&s[1]) && ft_atoi(&s[1]) <= REG_NUMBER)
		return (1);
	return (0);
}

int		is_dir(char *s)
{
	int i;

	i = 0;
	if (s[i] != '%')
		return (0);
	i++;
	if (s[i] != ':' && is_all_num(&s[i]) != 1)
		return (0);
	else if (is_all_num(&s[i]) == 1)
		return (1);
	if (s[i] == ':')
		while (s[++i] != '\0')
		{
			if (in_str(s[i], LABEL_CHARS) != 1)
				return (0);
		}
	else
		return (0);
	return (1);
}
