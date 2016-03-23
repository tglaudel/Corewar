/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_comment_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:42:59 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 13:48:37 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	format_name(char *s, int n, t_header *cor)
{
	int i;
	int j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != '"')
		return (0);
	i++;
	j = i;
	while (s[i] && s[i] != '"')
		i++;
	if (s[i] == '\0' || (n == 1 && i > PROG_NAME_LENGTH) ||\
	(n == 2 && i > COMMENT_LENGTH))
		return (0);
	if (n == 1)
		ft_strncpy(cor->prog_name, &s[j], i - j);
	else if (n == 2)
		ft_strncpy(cor->comment, &s[j], i - j);
	while (s[++i])
	{
		if (s[i] == COMMENT_CHAR)
			return (1);
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\0')
			return (0);
	}
	return (1);
}

int			is_comment(char *s, t_header *cor)
{
	if (s[0] == COMMENT_CHAR)
		return (1);
	if (ft_strncmp(s, NAME_CMD_STRING, NAME_CMD_STRING_LENGTH) == 0)
	{
		if (format_name(&s[NAME_CMD_STRING_LENGTH], 1, cor) == 1)
			return (1);
		else
			ft_errors("ERROR : is_comment(char *s, header_t *cor),\
			format_name not good", 1, 0);
	}
	else if (ft_strncmp(s, COMMENT_CMD_STRING, COMMENT_CMD_LENGTH) == 0)
	{
		if (format_name(&s[COMMENT_CMD_LENGTH], 2, cor) == 1)
			return (1);
		else
			ft_errors("ERROR : is_comment(char *s, header_t *cor),\
			format_comment not good", 1, 0);
	}
	return (0);
}
