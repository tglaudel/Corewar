/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:52:24 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/14 11:43:16 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static char		*my_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
	return (NULL);
}

static char		*get_champ_file(char *file, int width)
{
	int		fd;
	char	buf[COMMENT_NAME_MAGIC + width];
	int		i;
	char	*s;
	int ret;
	
	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_errors("ERROR : Fail open.", 1, 0);
	ret = read(fd, buf, COMMENT_NAME_MAGIC + width);
	if (ret > 0)
		if (!(s = (char*)malloc(sizeof(char) * COMMENT_NAME_MAGIC + width + 1)))
			ft_errors("ERROR : malloc.", 1, 0);
	while (++i <= COMMENT_NAME_MAGIC + width)
		s[i] = buf[i];
	return (s);
}

static int		check_find(t_env *e, int val)
{
	t_champ	*champ;

	champ = e->champ_start;
	while (champ != NULL)
	{
		if (champ->nb_champ == val)
			return (1);
		champ = champ->next;
	}
	return (0);
}

static void		check_nbchamp(t_env *env, t_champ *champ)
{
	if (env->player == NULL)
	{
		champ->nb_champ = -1;
		if (env->nb_champ == 1)
			return ;
		while (check_find(env, champ->nb_champ) != 0)
			champ->nb_champ -= 1;
	}
	if (env->player != NULL)
	{
		if (check_find(env, ft_atoi(env->player)) == 1)
			ft_errors("ERROR : name champ you cant have the same name", 1, 0);
		champ->nb_champ = ft_atoi(env->player);
		env->player = NULL;
	}
}

void			add_to_champ_lst(t_env *env, int nb, int width, char *file)
{
	t_champ	*champ;
	char	*s;

	if (!(champ = (t_champ*)malloc(sizeof(t_champ))))
		ft_errors("ERROR : Error malloc", 1, 0);
	if (env->champ_start == NULL)
		env->champ_start = champ;
	champ->nb_champ = -nb;
	check_nbchamp(env, champ);
	s = get_champ_file(file, width);
	champ->width = width;
	champ->color = nb;
	champ->name = ft_strsub(s, 4, PROG_NAME_LENGTH);
	champ->comment = ft_strsub(s, 12 + PROG_NAME_LENGTH, COMMENT_LENGTH);
	champ->code = my_strsub(s, COMMENT_NAME_MAGIC, width);
	champ->next = NULL;
	champ->nb_live = 0;
	champ->is_alive = 1;
	champ->pos = 0;
	champ->last_cycle_live = 0;
	if (env->champ_end != NULL)
		env->champ_end->next = champ;
	env->champ_end = champ;
	ft_strdel(&s);
	s = NULL;
}
