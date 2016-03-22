/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:14:30 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 17:14:46 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_def	*check_flags(const char *s, t_def *def)
{
	int i;

	i = 0;
	while (1)
	{
		if (s[i] == '#')
			def->format = 1;
		else if (s[i] == '-')
			def->ladj = 1;
		else if (s[i] == '+')
			def->sign = '+';
		else if (s[i] == ' ')
		{
			def->remp = ' ';
			if (def->sign == 0)
				def->sign = ' ';
		}
		else if (s[i] == '0')
			def->remp = '0';
		else
			break ;
		i++;
	}
	def->count = i;
	return (def);
}

t_def	*check_larg(const char *s, t_def *def, va_list lst)
{
	int i;

	i = 0;
	if (ft_isdigit(s[i]))
	{
		while (ft_isdigit(s[i]))
		{
			def->larg = 10 * def->larg + CTOD(s[i]);
			i++;
		}
		def->count = i;
	}
	else if (s[i] == '*')
	{
		def->larg = va_arg(lst, int);
		def->count = 1;
		if (def->larg < 0)
		{
			def->ladj = !def->ladj;
			def->larg = -def->larg;
		}
	}
	return (def);
}

t_def	*check_prec(const char *s, t_def *def, va_list lst)
{
	int i;

	i = 0;
	while (s[i] == '.')
	{
		i++;
		def->count++;
		def->prec = 0;
		if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
			{
				def->prec = 10 * def->prec + CTOD(s[i]);
				i++;
			}
			def->count = i;
		}
		else if (s[i] == '*')
		{
			def->prec = va_arg(lst, int);
			def->count = 2;
		}
	}
	return (def);
}

t_def	*check_modif(const char *s, t_def *def)
{
	int i;

	i = 0;
	while (s[i] == 'l' || s[i] == 'h' || s[i] == 'z' || s[i] == 'j')
	{
		if (s[i] == 'l')
			def->modif = 1;
		else if (s[i] == 'h' && def->modif == 6)
			def->modif = 5;
		else if (s[i] == 'h' && def->modif == 0)
			def->modif = 6;
		else if (s[i] == 'z' && def->modif == 0)
			def->modif = 4;
		else if (s[i] == 'j' && def->modif == 0)
			def->modif = 3;
		i++;
	}
	def->count = i;
	return (def);
}

t_def	*ft_def(const char *s, va_list lst, t_def *def)
{
	int		i;
	int		previ;

	previ = -1;
	i = 0;
	def = init_def(def);
	while (i != previ)
	{
		previ = i;
		def = check_flags(&s[i], def);
		i += def->count;
		def->count = 0;
		def = check_larg(&s[i], def, lst);
		i += def->count;
		def->count = 0;
		def = check_prec(&s[i], def, lst);
		i += def->count;
		def->count = 0;
		def = check_modif(&s[i], def);
		i += def->count;
		def->count = i;
	}
	return (def);
}
