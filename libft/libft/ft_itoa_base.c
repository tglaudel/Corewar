/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 08:28:46 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/08 12:06:32 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert(int n, int base, char *str, int i)
{
	int		div;
	char	tmp;

	div = 1;
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
	while (n / div >= base)
		div *= base;
	while (div > 0)
	{
		tmp = '0' + n / div;
		if (tmp > '9')
			str[i] = (tmp + 39);
		else
			str[i] = tmp;
		n %= div;
		div /= base;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(*str) * 12);
	i = 0;
	while (i < 12)
	{
		str[i] = '\0';
		i++;
	}
	i = 0;
	if (base != 10 && n < 0)
		n = -n;
	return (ft_convert(n, base, str, i));
}
