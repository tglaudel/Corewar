/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_odc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:03:33 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 07:59:35 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	create_odc(int opc, t_arg **tab)
{
	char			tmp;
	unsigned char	res;
	int				i;
	int				n;

	if (opc == 1 || opc == 9 || opc == 15 || opc == 12)
		return (0);
	n = 0;
	i = -1;
	res = 0;
	while (tab[++i])
	{
		ft_printf("%s\n", tab[i]->arg); //
		ft_printf("%d\n", (unsigned char)tab[i]->type); //
		ft_printf("%d\n", (unsigned char)tab[i]->size); //
		if (tab[i]->type == T_REG)
			tmp = REG_CODE;
		else if (tab[i]->type == T_DIR)
			tmp = DIR_CODE;
		else if (tab[i]->type == T_IND)
			tmp = IND_CODE;
		res = res | tmp;
		res = res << 2;
		n += 2;
	}
	while (n++ < 6)
		res = res << 1;
	return (res);
}
