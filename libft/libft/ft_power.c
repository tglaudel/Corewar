/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 08:59:52 by tglaudel          #+#    #+#             */
/*   Updated: 2015/12/03 09:32:27 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int n, unsigned int pow)
{
	int temp;

	if (pow == 0)
		return (1);
	temp = ft_power(n, pow / 2);
	if (pow % 2 == 0)
		return (temp * temp);
	else
		return (n * temp * temp);
}
