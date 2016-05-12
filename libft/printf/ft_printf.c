/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 13:01:59 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 20:58:31 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nprinted(va_list lst, const char *format, int i, int fd)
{
	int		ret;
	t_def	*def;

	ret = 0;
	def = (t_def*)malloc(sizeof(t_def));
	def->fd = fd;
	while (format[++i] != '\0')
	{
		(format[i] == '{' && c_col(&format[i])) ? i += p_col(&format[i]) : 0;
		if (format[i] == '%')
		{
			def = ft_def(&format[i + 1], lst, def);
			i += def->count + 1;
			if (format[i] == '\0')
				break ;
			ret += ft_istype(&format[i], lst, def);
		}
		else
		{
			ft_putchar_fd(format[i], def->fd);
			++ret;
		}
	}
	free(def);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list	lst;
	int		ret;

	ret = 0;
	va_start(lst, format);
	ret = nprinted(lst, format, -1, 1);
	va_end(lst);
	return (ret);
}

int		ft_printf_fd(int fd, const char *format, ...)
{
	va_list	lst;
	int		ret;

	ret = 0;
	va_start(lst, format);
	ret = nprinted(lst, format, -1, fd);
	va_end(lst);
	return (ret);
}
