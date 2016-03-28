/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:35:21 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/28 14:45:18 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_label	*new_label(void)
{
	t_label *new;

	if (!(new = (t_label*)malloc(sizeof(t_label))))
		ft_errors("ERROR : t_label	new_label(), error malloc", 1, 0);
	new->next = NULL;
	new->pos = 0;
	return (new);
}

static void		add_label(t_env *e, char *s, int n)
{
	t_label		*new;

	new = new_label();
	if (e->label_s == NULL)
		e->label_s = new;
	new->name = ft_strsub(s, 0, n);
	if (e->label_e != NULL)
		e->label_e->next = new;
	e->label_e = new;
	e->label_c = ft_strdup(new->name);
}

int				is_label(char *s, t_env *e)
{
	int i;
	int j;

	i = -1;
	while (s[++i] && s[i] != LABEL_CHAR)
	{
		if (in_str(s[i], LABEL_CHARS) != 1)
			return (0);
	}
	if (s[i] == '\0')
		return (0);
	j = i;
	add_label(e, s, j);
	while (s[++i])
		if (s[i] != '\t' && s[i] != ' ' && in_str(s[i], COMMENT_CHAR) != 1 &&\
		s[i] != '\0')
		{
			if (is_cmd(&s[i], e))
				return (1);
			else
				return (0);
		}
	return (1);
}
