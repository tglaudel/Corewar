/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 13:38:14 by tglaudel          #+#    #+#             */
/*   Updated: 2016/01/25 17:17:02 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# define CTOD(c) ((c) - '0')
# define MAXBUF (sizeof(long long int) * 8)
# define M0 0xC0
# define M1 0xE0
# define M2 0xF0
# define M3 0x80
# define M4 0xF0
# define M5 0x3F
# define M6 0x1F

typedef struct		s_def
{
	int			fd;
	int			flags;
	int			larg;
	int			ladj;
	int			remp;
	int			sign;
	int			sign_char;
	int			format;
	int			prec;
	int			modif;
	int			count;
	int			nul;
	const char	*prefix;
	const char	*digits;
}					t_def;

int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
int					ft_istype(const char *s, va_list lst, t_def *def);
int					print_num(unsigned long long u, t_def *def, int base, \
	int capitals);
int					print_string(va_list lst, t_def *def, int n);
int					print_wstring(va_list lst, t_def *def, int n, int i);
int					print_char(va_list lst, t_def *def, int n, char o);
int					print_wchar(unsigned int n, t_def *def);
int					print_ptr(va_list lst, t_def *def);
int					print_space(int n, char c, t_def *def);
int					nbits(unsigned int n);
t_def				*ft_def(const char *s, va_list lst, t_def *def);
t_def				*init_def(t_def *def);
unsigned long long	print_signed(va_list lst, t_def *def, int capitals);
unsigned long long	print_unsigned(va_list lst, t_def *def, int n,\
	int capitals);

#endif
