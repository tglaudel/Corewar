/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:15:58 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/28 11:46:48 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	char	*tmp_str;

	if (s1 && s2)
	{
		i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		str = ft_strnew(i);
		if (str == NULL)
			return (NULL);
		tmp_str = str;
		while (*s1)
			*tmp_str++ = *s1++;
		while (*s2)
			*tmp_str++ = *s2++;
		*tmp_str = '\0';
		return (str);
	}
	return (NULL);
}
