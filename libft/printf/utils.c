/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:43:28 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 16:48:35 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_def				*init_def(t_def *def)
{
	def->flags = 0;
	def->larg = 0;
	def->ladj = 0;
	def->remp = ' ';
	def->sign = 0;
	def->sign_char = 0;
	def->format = 0;
	def->prec = -1;
	def->modif = 0;
	def->count = 0;
	def->nul = 0;
	def->prefix = NULL;
	def->digits = "0123456789abcdef0123456789ABCDEF";
	return (def);
}

int					print_space(int n, char c, t_def *def)
{
	int i;

	i = 0;
	while (n-- > 0)
	{
		ft_putchar_fd(c, def->fd);
		i++;
	}
	return (i);
}

int					nbits(unsigned int n)
{
	int i;

	i = 1;
	while (n >>= 1)
		i++;
	return (i);
}

unsigned long long	print_signed(va_list lst, t_def *def, int capitals)
{
	unsigned long long	u;
	long long			n;

	if (def->modif == 1 || def->modif == 2 || def->modif == 3 || capitals || \
		def->modif == 4)
		n = va_arg(lst, long long);
	else if (def->modif == 5)
		n = (char)va_arg(lst, int);
	else if (def->modif == 6)
		n = (short int)va_arg(lst, int);
	else
		n = va_arg(lst, int);
	if (n >= 0)
	{
		u = n;
		def->sign_char = def->sign;
	}
	else
	{
		u = -n;
		def->sign_char = '-';
	}
	return (u);
}

unsigned long long	print_unsigned(va_list lst, t_def *def, int n, int capitals)
{
	unsigned long long u;

	if (def->modif == 1 || def->modif == 2 || def->modif == 3 || \
		def->modif == 4 || capitals)
		u = va_arg(lst, unsigned long long);
	else if (def->modif == 5)
		u = (unsigned char)va_arg(lst, int);
	else if (def->modif == 6)
		u = (unsigned short int)va_arg(lst, int);
	else
		u = va_arg(lst, unsigned int);
	if (n == 1)
		def->sign = 0;
	return (u);
}
