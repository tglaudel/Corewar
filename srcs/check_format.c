/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:11:21 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/22 19:02:33 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	format_name(char *s, int n)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	i++;
	while (s[i] != '"')
		i++;
	if (n == 1 && i > PROG_NAME_LENGTH)
		return (0);
	else if (n == 2 && i > COMMENT_LENGTH)
		return (0);
	return (1);
}

static int	is_comment(char *s)
{
	if (s[0] == COMMENT_CHAR)
		return (1);
	if (ft_strncmp(s, NAME_CMD_STRING, NAME_CMD_STRING_LENGTH) == 0)
	{
		if (format_name(&s[NAME_CMD_STRING_LENGTH], 1) == 1)
			return (1);
	}
	else if(ft_strncmp(s, COMMENT_CMD_STRING, COMMENT_CMD_LENGTH) == 0)
	{
		if (format_name(&s[COMMENT_CMD_LENGTH], 2) == 1)
			return (1);
	}
	return (0);
}

int 		is_good_format(char *s)
{
	if (is_comment(s))
		return (1);
	return (0);
}
