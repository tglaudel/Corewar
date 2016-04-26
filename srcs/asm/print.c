/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:18:17 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/29 12:02:14 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_comment(t_env *e)
{
	ft_printf("Programme size : %d bytes\n", e->pos_rel);
	ft_printf("Name           : %s\n", e->cor.prog_name);
	ft_printf("Comment        : %s\n\n", e->cor.comment);
}

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

void	print_opt_d(t_env *e, int i)
{
	t_cmd *tmp;

	tmp = e->cmd_s;
	e->name != NULL ? print_comment(e) : 0;
	while (tmp)
	{
		i = -1;
		ft_printf("Position(%3d) | size(%2d) | {red}OPC(%2d){none} | "\
		, tmp->pos_oct, tmp->size, tmp->opc);
		ft_printf("{blue}ODC(%4d){none} |", tmp->odc);
		while (tmp->tab[++i])
			ft_printf("{green} %s{none} |", tmp->tab[i]->arg);
		ft_printf("\n\t\t\t | {red}(0x%.2x){none}  | {blue}(0x%.2x){none}    |"\
		, tmp->octet[0], tmp->octet[1]);
		i = 0;
		if (tmp->odc > 0)
			i++;
		while (++i < tmp->size)
			ft_printf("{green} 0x%.2x{none} |", tmp->octet[i]);
		ft_putstr("\n\n");
		tmp = tmp->next;
	}
}

void	print_opt_o(t_env *e)
{
	t_cmd	*tmp;
	int		i;

	tmp = e->cmd_s;
	while (tmp)
	{
		i = -1;
		ft_putstr("# ");
		ft_printf("{red}0x%.2x{none} ", tmp->octet[++i]);
		if (tmp->odc > 0)
			ft_printf("{blue}0x%.2x{none} ", tmp->octet[++i]);
		while (++i < tmp->size)
			ft_printf("{green}0x%.2x{none} ", tmp->octet[i]);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
