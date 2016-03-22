/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:53:54 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 16:50:56 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		aff_string(const char *s, t_def *def, int i)
{
	int nprint;

	nprint = 0;
	if (def->larg > 0 && !def->ladj)
	{
		while (s[i] != '\0' && i < def->prec)
			i++;
		nprint += print_space(def->larg - i, def->remp, def);
	}
	i = 0;
	while ((i < def->prec) && *s != '\0')
	{
		if (*s == '\0')
			break ;
		ft_putchar_fd(*s++, def->fd);
		nprint++;
		i++;
	}
	if (i < def->larg && def->ladj)
		nprint += print_space(def->larg - i, ' ', def);
	return (nprint);
}

int				print_string(va_list lst, t_def *def, int n)
{
	int			i;
	const char	*s;
	int			nprint;

	s = NULL;
	nprint = 0;
	i = 0;
	if (def->prec <= -1)
		def->prec = 0x7fffffff;
	if (!n)
		s = va_arg(lst, char *);
	if (s == NULL || n)
		s = "(null)";
	nprint += aff_string(s, def, 0);
	return (nprint);
}

static int		ft_strwlen(const wchar_t *s, t_def *def)
{
	int i;
	int n;

	i = 0;
	while (*s != '\0' && i < def->prec)
	{
		n = nbits(*s) / 4;
		i += n;
		s++;
	}
	if (def->prec != 0x7fffffff)
		if (i > def->prec)
			i = i - n;
	return (i);
}

static int		prev_string(t_def *def, wchar_t *s)
{
	int i;
	int nprint;

	nprint = 0;
	i = 0;
	if (def->larg > 0 && !def->ladj)
	{
		i = ft_strwlen(s, def);
		nprint += print_space(def->larg - i, def->remp, def);
	}
	return (nprint);
}

int				print_wstring(va_list lst, t_def *def, int n, int i)
{
	int		nprint;
	wchar_t	*s;

	s = va_arg(lst, wchar_t *);
	if (def->prec <= -1)
		def->prec = 0x7fffffff;
	if (s == NULL)
		return (print_string(lst, def, 1));
	nprint = prev_string(def, s);
	while (s != NULL && *s != '\0')
	{
		i += nbits(*s) / 4;
		if (i > def->prec)
			break ;
		n = print_wchar((unsigned int)*s, def);
		def->larg -= n;
		nprint += n;
		s++;
	}
	if (def->larg > 0 && def->ladj)
	{
		i = ft_strwlen(s, def);
		nprint += print_space(def->larg - i, def->remp, def);
	}
	return (nprint);
}
