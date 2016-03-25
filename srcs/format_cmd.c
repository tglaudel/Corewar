/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:04:20 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/25 13:11:34 by tglaudel         ###   ########.fr       */
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

static int		get_size(t_arg **tab, int odc)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (tab[++i])
		n += tab[i]->size;
	if (odc != 0)
		n++;
	return (n + 1);
}

static int		format_cmd_size(char type, char *s, int n, int opc)
{
	if (type == T_DIR && opc == 9)
		return (T_DIR);
	if (type == T_IND && (opc == 3 || (opc == 11 && n == 1) || (opc == 13 && n == 0)))
		return (T_DIR);
	if (type == T_DIR && opc == 11 && n == 1)
		return (T_DIR);
	if (type == T_REG || type == T_IND)
		return (type);
	if (s[1] == ':')
		return (type);
	if (n == 2)
		return (type);
	return (T_IND);
}

static int		format_cmd_arg(char *s)
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

static t_arg	**get_cmd_arg(char *s, int opc)
{
	int		i;
	t_arg	**tab;
	char	**arg;
	int		nb_arg;

	i = 0;
	while (s[i] != ' ' && s[i] != '\t')
		i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	arg = ft_strsplit(&s[i], SEPARATOR_CHAR);
	nb_arg = len_tab(arg);
	tab = (t_arg**)malloc(sizeof(t_arg*) * nb_arg + 1);
	i = 0;
	while (nb_arg--)
	{
		tab[i] = (t_arg*)malloc(sizeof(t_arg));
		tab[i]->type = format_cmd_arg(arg[i]);
		tab[i]->arg = format_str(arg[i]);
		tab[i]->size = format_cmd_size(tab[i]->type, tab[i]->arg, i, opc);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static t_cmd	*new_cmd(void)
{
	t_cmd *new;

	if (!(new = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_errors("ERROR : t_label	new_cmd(), error malloc", 1, 0);
	new->next = NULL;
	new->odc = 0;
	new->pos_oct = 0;
	new->size = 0;
	new->label = NULL;
	new->tab = NULL;
	new->opc = 0;
	return (new);
}

static void		add_cmd(t_env *e, char *s, int n)
{
	t_cmd		*new;

	new = new_cmd();
	if (e->cmd_s == NULL)
		e->cmd_s = new;
	new->opc = n;
	new->tab = get_cmd_arg(s, n);
	new->odc = create_odc(n, new->tab);
	new->size = get_size(new->tab, new->odc);
	new->pos_oct = e->pos_rel;
	if (e->label_c != NULL)
	{
		new->label = ft_strdup(e->label_c);
		ft_strdel(&e->label_c);
	} 
	e->pos_rel += new->size;
	if (e->cmd_e != NULL)
		e->cmd_e->next = new;
	e->cmd_e = new;
}

static int		check_cmd(char *s, int nb_arg, int op)
{
	int		i;
	int		n;
	char	**arg;

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
		//ft_printf("arg %s %d : '%s'\n", g_op_tab[op].name, n, arg[n]); debug
		if ((format_cmd_arg(arg[n]) & g_op_tab[op].i[n]) == 0)
			return (0);
		n++;
	}
	return (1);
}

int				is_cmd(char *s, t_env *e)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	while (g_op_tab[n].name != 0)
	{
		if (ft_strncmp(&s[i], g_op_tab[n].name, \
			ft_strlen(g_op_tab[n].name)) == 0)
			if (check_cmd(&s[i + ft_strlen(g_op_tab[n].name)], \
			g_op_tab[n].nb_arg, n) == 1)
			{
				add_cmd(e, &s[i], g_op_tab[n].op_code);
				// ft_putstr("CMD Valide : "); debug
				// ft_putendl(&s[i]);
				return (1);
			}
		n++;
	}
	return (0);
}
