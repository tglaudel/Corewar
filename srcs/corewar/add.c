/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:20:43 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/04 16:06:27 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// il prendre en parametre {REG, REG, REG}
//
// il va donc prendre trois registres et additionne les valeurs des deux
// premiers et stockera le resultat dans le troisieme. Il modifiera le carry.

int add(t_env *e, t_proc *proc)
{
	if (proc->inst.arg[0] > REG_NUMBER)

}
