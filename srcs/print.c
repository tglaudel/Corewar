/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:18:17 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/24 16:21:15 by tglaudel         ###   ########.fr       */
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
	t_cmd *tmp;
	int i;

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
