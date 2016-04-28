/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:10:17 by fgiraud           #+#    #+#             */
/*   Updated: 2016/04/28 13:12:44 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lldi(struct env, index1, index2, reg)
{
	//pas de IDX_MOD ici aux adresses
	reg = env->mem[(index1 + index2)];
	process->carr = 1;
}
