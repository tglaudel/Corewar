/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:21:23 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/29 14:40:53 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
			i++;
		start = i;
		if (s[i] == '\0')
			return (ft_strdup(""));
		while (s[i] != '\0')
			i++;
		while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ' || s[i] == '\0')
			i--;
		end = i;
		str = ft_strsub(s, start, end - start + 1);
		return (str);
	}
	return ((char*)s);
}
