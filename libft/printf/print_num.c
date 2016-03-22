/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:30:51 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 16:49:50 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			prev_print_num_second(t_def *def, char *p)
{
	int nprint;

	nprint = 0;
	if (def->prefix && p != NULL && (def->nul == 0 || def->prefix[1] == '\0'))
	{
		ft_putstr(def->prefix);
		nprint += ft_strlen(def->prefix);
	}
	if (def->remp == '0' && !def->ladj)
	{
		if (def->prec == -1)
			nprint += print_space(def->larg, ' ', def);
		else
			nprint += print_space(def->larg, '0', def);
	}
	return (nprint);
}

static int			prev_print_num(t_def *def, int base, int capitals, char *p)
{
	int nprint;

	nprint = 0;
	if (def->format == 1)
	{
		if (base == 8 && (def->prec != -1 || def->nul))
			def->prefix = "0";
		else if (base == 16 && capitals == 0)
			def->prefix = "0x";
		else if (base == 16 && capitals == 16)
			def->prefix = "0X";
	}
	if ((def->sign || def->sign_char == '-') && base == 10)
		def->larg--;
	if (def->prefix)
		def->larg -= (int)ft_strlen(def->prefix);
	if (!def->ladj && (def->remp == ' ' || def->prec == 0))
		nprint += print_space(def->larg, ' ', def);
	if ((def->sign_char == '-' || def->sign) && base == 10)
	{
		ft_putchar(def->sign_char);
		nprint++;
	}
	return (nprint + prev_print_num_second(def, p));
}

static int			u_null(t_def *def, unsigned long long u)
{
	int n;

	n = 0;
	if (def->prec != -1)
		def->remp = ' ';
	if (u == 0)
	{
		if (def->prec <= -1)
		{
			n = 1;
			def->prec--;
			def->format = 0;
		}
		def->nul = 1;
	}
	return (n);
}

int					print_num(unsigned long long u, t_def *def, int base,\
	int capitals)
{
	char	buf[MAXBUF];
	char	*p;
	int		nprint;

	p = &buf[MAXBUF - 1];
	if (u_null(def, u) == 1)
		*p-- = '0';
	while (u != 0)
	{
		*p-- = def->digits[(u % base) + capitals];
		u /= base;
		def->prec--;
	}
	while (def->prec-- > 0)
		*p-- = '0';
	def->larg -= (int)(&buf[MAXBUF - 1] - p);
	nprint = prev_print_num(def, base, capitals, p);
	while (++p != &buf[MAXBUF])
	{
		ft_putchar_fd(*p, def->fd);
		nprint++;
	}
	if (def->ladj)
		nprint += print_space(def->larg, ' ', def);
	return (nprint);
}
