/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_octet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:35:07 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/25 15:36:23 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	convert_to_octet(t_cmd *start)
{
	t_cmd *tmp;
	int i;
	int n;

	tmp = start;
	while (tmp)
	{
		n = -1;
		i = 0;
		tmp->octet = (unsigned char*)malloc(sizeof(unsigned char)* tmp->size);
		tmp->octet[i++] = tmp->opc;
		if (tmp->odc > 0)
			tmp->octet[i++] = tmp->odc;
		while (tmp->tab[++n])
		{
			if (tmp->tab[n]->size == T_REG)
			 	tmp->octet[i++] = tmp->tab[n]->arg[1] - '0';
			else if (tmp->tab[n]->size == T_DIR)
			{
				tmp->octet[i++] = 0;
				tmp->octet[i++] = 0;
			}
			else if (tmp->tab[n]->size == T_IND)
			{
				tmp->octet[i++] = tmp->tab[n]->arg[0] - '0';
				tmp->octet[i++] = tmp->tab[n]->arg[1] - '0';
				tmp->octet[i++] = tmp->tab[n]->arg[2] - '0';
				tmp->octet[i++] = tmp->tab[n]->arg[3] - '0';
			}
		}
		tmp = tmp->next;
	}

}
