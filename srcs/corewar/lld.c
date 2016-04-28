/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:07:16 by fgiraud           #+#    #+#             */
/*   Updated: 2016/04/28 13:23:36 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lld(struct process, int val, int reg)
{
	//pas de modulo IDX_MOD ici
	process->reg[reg] = val;
	process->carry = 1;
}
