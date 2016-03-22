/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:37:50 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/28 11:45:38 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	if (s)
	{
		str = (unsigned char*)s;
		while (n--)
		{
			if (*str == (unsigned char)c)
				return ((void*)str);
			str++;
		}
	}
	return (NULL);
}
