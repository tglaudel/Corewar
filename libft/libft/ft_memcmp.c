/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:02:40 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/25 19:13:07 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *st1;
	unsigned char *st2;

	if (s1 && s2)
	{
		st1 = (unsigned char*)s1;
		st2 = (unsigned char*)s2;
		while (n > 0)
		{
			if (*st1 != *st2)
				return (*st1 - *st2);
			st1++;
			st2++;
			n--;
		}
	}
	return (0);
}
