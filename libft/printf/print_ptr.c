/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:04:25 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 16:50:06 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_ptr(va_list lst, t_def *def)
{
	int					nprint;
	unsigned long long	p;

	nprint = 0;
	p = (unsigned long long)va_arg(lst, void*);
	if (p == 0 && !def->ladj)
	{
		if (def->remp == '0')
			ft_putstr_fd("0x", def->fd);
		nprint += print_space(def->larg - 3, def->remp, def);
		if (def->remp == ' ')
			ft_putstr_fd("0x", def->fd);
		def->larg = 0;
		nprint += 2;
	}
	if (p == 0 && def->ladj)
	{
		ft_putstr_fd("0x", def->fd);
		def->larg -= 2;
		def->larg = -def->larg;
		nprint += 2;
	}
	nprint += ft_printf("%#*.*llx", def->larg, def->prec, p);
	return (nprint);
}
