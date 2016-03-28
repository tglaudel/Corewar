/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:56:36 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 18:59:25 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				get_size(t_arg **tab, int odc)
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

int				format_cmd_size(char type, char *s, int n, int opc)
{
	if (type == T_DIR && (opc == 9 || opc == 14 || opc == 12 || opc == 15))
		return (T_DIR);
	if (type == T_DIR && (opc == 2 || opc == 7 || opc == 8 || opc == 6 || opc == 13))
		return (T_IND);
	if (type == T_IND && (opc == 10 || opc == 14 || opc == 13))
		return (T_DIR);
	if (type == T_DIR && opc == 10)
		return (T_DIR);
	if (type == T_IND && (opc == 3 || (opc == 11 && n == 1) \
	|| opc == 6 || opc == 7 || opc == 8 || opc == 2))
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

t_cmd			*new_cmd(void)
{
	t_cmd *new;

	if (!(new = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_errors("ERROR : t_label	new_cmd(), error malloc", 1, 0);
	new->next = NULL;
	new->odc = 0;
	new->pos_oct = 0;
	new->size = 0;
	new->tab = NULL;
	new->opc = 0;
	return (new);
}

void			add_cmd(t_env *e, char *s, int n)
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
	e->pos_rel += new->size;
	if (e->cmd_e != NULL)
		e->cmd_e->next = new;
	e->cmd_e = new;
}
