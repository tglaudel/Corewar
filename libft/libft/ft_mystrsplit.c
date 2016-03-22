/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mystrsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:15:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/22 17:23:08 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		mylenword(const char *s)
{
	int i;

	i = 0;
	while (s[i] != ' ' && s[i] != '\t' &&s[i] != '\0')
		i++;
	return (i);
}

static int		mycountword(const char *s)
{
	int i;
	int nbw;

	nbw = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			nbw++;
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
				i++;
		}
	}
	return (nbw);
}

char			**ft_mystrsplit(char const *s)
{
	char	**str;
	int		index;
	int		nbw;

	index = 0;
	nbw = mycountword((const char*)s);
	str = (char**)malloc(sizeof(*str) * \
			(mycountword((const char *)s) + 1));
	if (str == NULL)
		return (NULL);
	while (nbw--)
	{
		while (*s == ' ' && *s == '\t' && *s != '\0')
			s++;
		str[index] = ft_strsub((const char *)s, 0, \
				mylenword((const char*)s));
		if (str[index] == NULL)
			return (NULL);
		s = s + mylenword(s);
		index++;
	}
	str[index] = NULL;
	return (str);
}
