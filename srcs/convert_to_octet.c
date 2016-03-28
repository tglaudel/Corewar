/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_octet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:35:07 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 16:51:23 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		search_label(t_label *start, char *s, int pos)
{
	t_label *tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, s) == 0)
			return (tmp->pos - pos);
		tmp = tmp->next;
	}
	ft_errors("ERROR : Label not exist.", 0, 0);
	return (0);
}

static int		int_to_dir(unsigned char *octet, char *s, int pos, t_label *lab)
{
	unsigned short int	i;
	int					n;

	n = 0;
	if (s[0] == '%')
		n++;
	if (s[1] == ':')
	{
		i = search_label(lab, &s[2], pos);
		octet[0] = i >> 8;
		octet[1] = i;
	}
	else if (is_all_num(&s[0 + n]))
	{
		i = ft_atoi(&s[0 + n]);
		octet[0] = i >> 8;
		octet[1] = i;
	}
	return (2);
}

static int		char_to_octet(t_cmd *tmp, t_arg *arg, t_label *lab, int i)
{
	unsigned int	x;
	int				n;

	n = 0;
	if (arg->arg[0] == '%')
		n = 1;
	if (arg->size == T_REG)
	{
		tmp->octet[i] = ft_atoi(&arg->arg[1]);
		return (1);
	}
	if (arg->size == T_DIR)
		return (int_to_dir(&tmp->octet[i], arg->arg, tmp->pos_oct, lab));
	if (arg->size == T_IND)
	{
		x = ft_atoi(&arg->arg[1]);
		tmp->octet[i] = x >> 24;
		tmp->octet[i + 1] = x >> 16;
		tmp->octet[i + 2] = x >> 8;
		tmp->octet[i + 3] = x;
		return (4);
	}
	return (0);
}

void			convert_to_octet(t_cmd *start, t_label *lab)
{
	t_cmd	*tmp;
	int		i;
	int		n;

	tmp = start;
	while (tmp)
	{
		n = -1;
		i = 0;
		tmp->octet = (unsigned char*)malloc(sizeof(unsigned char) * tmp->size);
		tmp->octet[i++] = tmp->opc;
		if (tmp->odc > 0)
			tmp->octet[i++] = tmp->odc;
		while (tmp->tab[++n])
			i += char_to_octet(tmp, tmp->tab[n], lab, i);
		tmp = tmp->next;
	}
}
