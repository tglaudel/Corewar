/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_octet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:35:07 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 11:31:37 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static unsigned int		search_label(t_label *start, char *s, int pos)
{
	t_label *tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, s) == 0)
			return (tmp->pos - pos);
		tmp = tmp->next;
	}
	ft_errors("ERROR : Label not exist.", 1, 0);
	return (0);
}

static int				int_to_dir(unsigned char *octet, char *s, int pos,\
	t_label *lab)
{
	unsigned short int	i;
	int					n;

	n = 0;
	i = 0;
	if (s[0] == '%')
		n++;
	if (s[1] == ':')
		i = search_label(lab, &s[2], pos);
	else if (s[0] == ':')
		i = search_label(lab, &s[1], pos);
	else if (is_all_num(&s[n]))
	{
		if (ft_strlen(&s[n]) > 20 && s[n] == '-')
			i = 0;
		else if (ft_strlen(&s[n]) > 20)
			i = 65535;
		else
			i = ft_atoi(&s[n]);
	}
	octet[0] = i >> 8;
	octet[1] = i;
	return (2);
}

static int				int_to_ind(unsigned char *octet, char *s, int pos,\
	t_label *lab)
{
	unsigned int	i;
	int				n;

	n = 0;
	i = 0;
	if (s[0] == '%')
		n++;
	if (s[0] == ':' || s[1] == ':')
		i = search_label(lab, &s[n + 1], pos);
	else if (is_all_num(&s[n]))
	{
		if (ft_strlen(&s[n]) >= 20)
			i = -1;
		else
			i = (unsigned int)ft_atod(&s[0 + n]);
	}
	octet[0] = i >> 24;
	octet[1] = i >> 16;
	octet[2] = i >> 8;
	octet[3] = i;
	return (4);
}

static int				char_to_octet(t_cmd *tmp, t_arg *arg, t_label *lab,\
	int i)
{
	if (arg->size == T_REG)
	{
		tmp->octet[i] = ft_atoi(&arg->arg[1]);
		if (tmp->octet[i] <= 0 || tmp->octet[i] > 16)
			ft_errors("ERROR : 1 <= registre <= 16.", 1, 0);
		return (1);
	}
	else if (arg->size == T_DIR)
		return (int_to_dir(&tmp->octet[i], arg->arg, tmp->pos_oct, lab));
	else if (arg->size == T_IND)
		return (int_to_ind(&tmp->octet[i], arg->arg, tmp->pos_oct, lab));
	return (0);
}

void					convert_to_octet(t_cmd *start, t_label *lab)
{
	t_cmd	*tmp;
	int		i;
	int		n;

	tmp = start;
	while (tmp)
	{
		n = -1;
		i = 0;
		if (!(tmp->octet = (unsigned char*)malloc(sizeof(unsigned char)\
		* tmp->size)))
			ft_errors("ERROR : petit malloc des familles", 1, 0);
		tmp->octet[i++] = tmp->opc;
		if (tmp->odc > 0)
			tmp->octet[i++] = tmp->odc;
		while (tmp->tab[++n])
			i += char_to_octet(tmp, tmp->tab[n], lab, i);
		tmp = tmp->next;
	}
}
