/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:52:42 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/29 12:01:11 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_tab(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		ft_strdel(&s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

void		free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd)
	{
		i = 0;
		tmp = cmd->next;
		while (cmd->tab[i])
		{
			ft_strdel(&cmd->tab[i]->arg);
			free(cmd->tab[i]);
			cmd->tab[i] = NULL;
			i++;
		}
		free(cmd->tab);
		cmd->tab = NULL;
		ft_strdel((char**)&cmd->octet);
		free(cmd);
		cmd = NULL;
		cmd = tmp;
	}
}

void		free_label(t_label *label)
{
	t_label *tmp;

	while (label)
	{
		tmp = label->next;
		ft_strdel(&label->name);
		free(label);
		label = NULL;
		label = tmp;
	}
}

void		free_all(t_env *e)
{
	e->cmd_s != NULL ? free_cmd(e->cmd_s) : 0;
	e->label_s != NULL ? free_label(e->label_s) : 0;
	e->name != NULL ? ft_strdel(&e->name) : 0;
}
