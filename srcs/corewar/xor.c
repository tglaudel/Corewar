/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:32:18 by fgiraud           #+#    #+#             */
/*   Updated: 2016/04/28 11:42:01 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	and(process, val1, val2, *reg)
{
	reg = val1 ^ val2;
	process->carry = 1;
}