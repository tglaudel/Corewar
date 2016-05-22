/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:52:31 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 17:20:07 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_putchar_ret(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static int		aff_char(unsigned int c, t_def *def, int n)
{
	int nprint;

	nprint = 0;
	if (def->larg > 0 && !def->ladj)
		nprint += print_space(def->larg - 1, def->remp, def);
	if (n == 0)
		nprint += ft_putchar_ret(c, def->fd);
	else
		nprint += print_wchar(c, def);
	if (def->larg && def->ladj)
		nprint += print_space(def->larg - 1, ' ', def);
	return (nprint);
}

int				print_char(va_list lst, t_def *def, int n, char o)
{
	unsigned int	c;
	int				nprint;

	nprint = 0;
	if (def->prec == -1)
		def->prec = 0x7fffffff;
	if (def->modif == 2 || def->modif == 1)
		n = 1;
	if (n == 0 && !o)
		c = va_arg(lst, unsigned int);
	else if (!o)
		c = (unsigned int)va_arg(lst, wchar_t);
	else
		c = (unsigned int)o;
	if (c == 0)
	{
		c = '\0';
	}
	nprint += aff_char(c, def, n);
	return (nprint);
}

int				print_wchar(unsigned int n, t_def *def)
{
	int i;
	int octet;

	octet = 0;
	i = nbits(n);
	if (i > 7)
	{
		if (i > 11)
		{
			if (i > 16)
			{
				octet += ft_putchar_ret(((n >> 18) & 7) | M2, def->fd);
				octet += ft_putchar_ret(((n >> 12) & M5) | M3, def->fd);
			}
			else
				octet += ft_putchar_ret(((n >> 12) & 15) | M1, def->fd);
			octet += ft_putchar_ret(((n >> 6) & M5) | M3, def->fd);
		}
		else
			octet += ft_putchar_ret(((n >> 6) & M6) | M0, def->fd);
		octet += ft_putchar_ret((n & M5) | M3, def->fd);
	}
	else
		octet += ft_putchar_ret(n, def->fd);
	return (octet);
}
