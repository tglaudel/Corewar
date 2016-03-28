/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:38:16 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 11:16:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_col		g_col[13] =
{
	{0, "none", C_NONE},
	{1, "red", C_RED},
	{2, "red2", C_RED2},
	{3, "green", C_GREEN},
	{4, "green2", C_GREEN2},
	{5, "yellow", C_YELLOW},
	{6, "yellow2", C_YELLOW2},
	{7, "blue", C_BLUE},
	{8, "blue2", C_BLUE2},
	{9, "magenta", C_MAGENTA},
	{10, "cyan", C_CYAN},
	{11, "gray", C_GRAY},
	{12, "black", C_BLACK}
};

int		p_col(const char *s)
{
	int i;
	int n;

	n = -1;
	i = 0;
	while (s[i] != '\0' && s[i] != '}')
		i++;
	while (g_col[++n].n < 12)
	{
		if (ft_strncmp(&s[1], g_col[n].name, i - 1) == 0)
		{
			ft_putstr(g_col[n].color);
			break ;
		}
	}
	return (i + 1);
}

int		c_col(const char *s)
{
	unsigned long	i;
	int				n;

	i = 0;
	n = -1;
	while (s[i] != '\0' && s[i] != '}')
		i++;
	if (s[i] == '\0')
		return (0);
	else
	{
		while (g_col[++n].n < 12)
		{
			if (i - 1 == ft_strlen(g_col[n].name))
				if (ft_strncmp(&s[1], g_col[n].name, i - 1) == 0)
					return (1);
		}
	}
	return (0);
}
