/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:11:21 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 14:58:57 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_good_format(char *s, t_header *cor, t_env *e)
{
	(void)e;
	if (is_comment(s, cor))
		return (1);
	else if (is_label(s, e))
		return (1);
	else if (is_cmd(s, e))
		return (1);
	return (0);
}
