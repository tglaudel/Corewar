/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:23:58 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/03 09:32:54 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbint(int n)
{
	int nbint;

	if (n == 0)
		return (1);
	nbint = 0;
	while (n != 0)
	{
		nbint++;
		n = n / 10;
	}
	return (nbint);
}

static int		ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int		ft_vabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char			*ft_itoa(int n)
{
	int		nbint;
	int		sign;
	char	*result;

	nbint = ft_nbint(n);
	sign = ft_sign(n);
	result = (char*)malloc(sizeof(char) * (nbint + sign + 1));
	if (result)
	{
		result = result + nbint + sign;
		*result = '\0';
		if (n == 0)
			*--result = '0';
		while (n != 0)
		{
			*--result = ft_vabs(n % 10) + '0';
			n /= 10;
		}
		if (sign == 1)
			*--result = '-';
	}
	return (result);
}
