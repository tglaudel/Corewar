/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:17:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 16:23:21 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_cap(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (16);
	return (0);
}

int		ft_istype(const char *s, va_list lst, t_def *def)
{
	if (*s == 'd' || *s == 'i' || *s == 'D')
		return (print_num(print_signed(lst, def, is_cap(*s)), def, 10, 0));
	else if (*s == 'c' || *s == 'C')
		return (print_char(lst, def, is_cap(*s), 0));
	else if (*s == 'u' || *s == 'U')
		return (print_num(print_unsigned(lst, def, 1, is_cap(*s)), def, 10, 0));
	else if (*s == 'o' || *s == 'O')
		return (print_num(print_unsigned(lst, def, 0, is_cap(*s)), def, 8,\
		is_cap(*s)));
	else if (*s == 'x' || *s == 'X')
		return (print_num(print_unsigned(lst, def, 0, 0), def, 16, is_cap(*s)));
	else if (*s == 'S' || (*s == 's' && def->modif == 1))
		return (print_wstring(lst, def, 0, 0));
	else if (*s == 's')
		return (print_string(lst, def, 0));
	else if (*s == 'p')
		return (print_ptr(lst, def));
	else if (*s != '\0')
		return (print_char(lst, def, 0, *s));
	return (0);
}
