/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:11:21 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 21:07:01 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	is_nothing_john_snow(char *s)
{
	int i;

	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int			is_good_format(char *s, t_header *cor, t_env *e)
{
	if (is_comment(s, cor))
		return (1);
	else if (is_label(s, e))
		return (1);
	else if (is_cmd(s, e))
		return (1);
	else if (is_nothing_john_snow(s))
		return (1);
	return (0);
}
