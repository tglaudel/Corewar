/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:18:17 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/24 17:52:51 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_label(t_label *start)
{
	t_label *tmp;

	tmp = start;
	ft_putendl("\nLabels :");
	while (tmp)
	{
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
}

void	print_cmd(t_cmd *start)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = start;
	ft_putendl("\nCMD :");
	while (tmp)
	{
		i = 0;
		ft_printf("OPC : %d\n", tmp->opc);
		while (tmp->tab[i])
		{
			ft_printf("arg type    %d : %d\n", i, tmp->tab[i]->type);
			ft_printf("arg content %d : %s\n", i, tmp->tab[i]->arg);
			i++;
		}
		ft_putstr("----\n");
		tmp = tmp->next;
	}
}

void	print_opt_a(t_env *e)
{
	int i;
	t_cmd *tmp;

	tmp = e->cmd_s;
	i = 0;
	ft_printf("Programme size : %d bytes\n", e->pos_rel);
	ft_printf("Name           : %s\n", e->cor.prog_name);
	ft_printf("Comment        : %s\n", e->cor.comment);
	while (tmp)
	{
		i = -1;
		if (tmp->label)
			ft_printf("Label_Position(%4d)", tmp->pos_oct);
		ft_printf("Position(%3d) | size(%2d) | OPC(%2d) | ", tmp->pos_oct, tmp->size, tmp->opc);
		ft_printf("ODC(%4d) |", tmp->odc);
		while (tmp->tab[++i])
			ft_printf(" %s |", tmp->tab[i]->arg);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
