/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:43:51 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/27 08:31:14 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (*s2 == '\0')
		return ((char*)s1);
	i = ft_strlen(s2);
	while (*s1 != '\0' && n >= i)
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, i) == 0)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
