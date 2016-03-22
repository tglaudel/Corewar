/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:17:15 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/25 19:04:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	if (!s1 || !s2)
		return (NULL);
	if (*s2 == '\0')
		return ((char*)s1);
	i = ft_strlen(s2);
	while (*s1)
	{
		if (ft_strncmp(s1, s2, i) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
