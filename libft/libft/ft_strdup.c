/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:45:50 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/24 15:41:43 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	int		n;

	n = 0;
	i = ft_strlen(s);
	if ((str = (char *)malloc(i * sizeof(*str) + 1)))
	{
		while (n < i)
		{
			str[n] = s[n];
			n++;
		}
		str[n] = '\0';
		return (str);
	}
	return (NULL);
}
