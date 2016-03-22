/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:55:44 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/03 15:37:45 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	else
	{
		i = ft_strlen(s);
		while (s[i] != c && i != 0)
			i--;
		if (s[i] == c)
			return ((char *)s + i);
		else
			return (0);
	}
}
