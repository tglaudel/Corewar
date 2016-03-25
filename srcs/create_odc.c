/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_odc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:03:33 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/25 11:57:21 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	create_odc(int opc, t_arg **tab)
{
	char	tmp;
	unsigned char	res;
	int		i;
	int		n;

	if (opc == 1 || opc == 9 || opc == 15 || opc == 12)
		return (0);
	n = 0;
	i = -1;
	res = 0;
	while (tab[++i])
	{
		if (tab[i]->type == T_REG)
			tmp = REG_OPC;
		else if (tab[i]->type == T_DIR)
			tmp = DIR_OPC;
		else if (tab[i]->type == T_IND)
			tmp = IND_OPC;
		res = res | tmp;
		res = res << 2;
		n += 2;
	}
	while (n++ < 6)
		res = res << 1;
	return (res);
}
