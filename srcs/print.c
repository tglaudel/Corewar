/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:18:17 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 14:27:40 by tglaudel         ###   ########.fr       */
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
