/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:41:53 by fgiraud           #+#    #+#             */
/*   Updated: 2016/04/28 10:37:20 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		live(struct env, val live)
{
	if (live >= -4 && <= -1)
	{
		while (env->player != NULL)
		{
			if (env->player->name == live)
				return (1);
			env->player = env->player->next;
		}
	}
	return (-1);
}
