/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:04:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 19:51:17 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2},
	{"st", 2, {T_REG, T_IND | T_REG}, 3},
	{"add", 3, {T_REG, T_REG, T_REG}, 4},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8},
	{"zjmp", 1, {T_DIR}, 9},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11},
	{"fork", 1, {T_DIR}, 12},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14},
	{"lfork", 1, {T_DIR}, 15},
	{"aff", 1, {T_REG}, 16},
	{0, 0, {0}, 0}
};



static int	format_cmd_arg(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (is_ind(&s[i]) == 1)
		return (T_IND);
	else if (is_dir(&s[i]) == 1)
		return (T_DIR);
	else if (is_reg(&s[i]) == 1)
		return (T_REG);
	return (0);
}

static int	check_cmd(char *s, int nb_arg, int op)
{
	int i;
	int n;
	char **arg;

	(void)op;
	n = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	arg = ft_strsplit(s, SEPARATOR_CHAR);
	if (nb_arg != len_tab(arg))
		return (0);
	while (nb_arg--)
	{
		ft_printf("arg %s %d : '%s'\n", g_op_tab[op].name, n, arg[n]);
		if ((format_cmd_arg(arg[n]) & g_op_tab[op].i[n]) == 0)
			return (0);
		n++;
	}
	return (1);
}

int			is_cmd(char *s, t_env *e)
{
	int i;
	int n;

	n = 0;
	i = 0;
	(void)e;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	while (g_op_tab[n].name != 0)
	{
		if (ft_strncmp(&s[i], g_op_tab[n].name, ft_strlen(g_op_tab[n].name)) == 0)
			if (check_cmd(&s[i + ft_strlen(g_op_tab[n].name)], g_op_tab[n].nb_arg, n) == 1)
			{
				ft_putstr("CMD Valide : ");
				ft_putendl(&s[i]);
				return (1);
			}
		n++;
	}
	return (0);
}
