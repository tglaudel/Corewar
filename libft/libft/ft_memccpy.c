/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:43:29 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/27 08:10:38 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	if (dst && src && n)
	{
		while (i < n)
		{
			((char*)dst)[i] = ((char*)src)[i];
			if (((char*)src)[i] == (char)c)
				return ((char*)dst + i + 1);
			i++;
		}
	}
	return (NULL);
}
