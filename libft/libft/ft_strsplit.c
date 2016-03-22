/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:22:36 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/22 17:20:59 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		index;
	int		nbw;

	index = 0;
	nbw = ft_count_word((const char*)s, c);
	str = (char**)malloc(sizeof(*str) * \
			(ft_count_word((const char *)s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (nbw--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[index] = ft_strsub((const char *)s, 0, \
				ft_lenword((const char*)s, c));
		if (str[index] == NULL)
			return (NULL);
		s = s + ft_lenword(s, c);
		index++;
	}
	str[index] = NULL;
	return (str);
}
