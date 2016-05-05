/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:56:20 by fgiraud           #+#    #+#             */
/*   Updated: 2016/05/05 13:36:23 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int			fork_cor(t_env *e, t_proc *proc)
{
	int 	pos;
	int		pos_papa;

	pos_papa = (proc->pc + (proc->inst.arg[0] % IDX_MOD));
	if ((pos = pos_papa % MEM_SIZE) < 0)
		pos = MEM_SIZE - pos;
	new_processus(e, 0, pos, proc);
	return (1);
}
