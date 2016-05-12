/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_comment_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 10:42:59 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 19:21:52 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	name_ok(header_t *cor)
{
	if (cor->prog_name[0] != '\0')
		return (1);
	else
		ft_errors("ERROR : name vide", 1, 0);
	return (0);
}

static int	format_name(char *s, int n, header_t *cor)
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
	n == 1 ? ft_strncpy(cor->prog_name, &s[j], i - j) : \
	ft_strncpy(cor->comment, &s[j], i - j);
	while (s[++i])
	{
		if (in_str(s[i], COMMENT_CHAR))
			return (1);
		if (s[i] != '\t' && s[i] != ' ' && s[i] != '\0')
			return (0);
	}
	return (1);
}

int			is_comment(char *s, header_t *cor)
{
	int i;

	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	if (in_str(s[i], COMMENT_CHAR))
		return (1);
	if (ft_strncmp(s, NAME_CMD_STRING, NAME_CMD_STRING_LENGTH) == 0)
	{
		if (cor->prog_name[0] == '\0' && format_name(&s[NAME_CMD_STRING_LENGTH]\
			, 1, cor) == 1)
			return (name_ok(cor));
		else
			ft_errors("ERROR : NAME", 1, 0);
	}
	else if (ft_strncmp(s, COMMENT_CMD_STRING, COMMENT_CMD_LENGTH) == 0)
	{
		if (cor->comment[0] == '\0' && format_name(&s[COMMENT_CMD_LENGTH], 2,\
			cor) == 1)
			return (1);
		else
			ft_errors("ERROR : COMMENT", 1, 0);
	}
	return (0);
}
