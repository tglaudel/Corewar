/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:52:24 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/28 10:05:05 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

static char	*my_strsub(char const *s, unsigned int start, size_t len)
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

void		add_to_champ_lst(t_env *env, int nb, int width, char *file)
{
	t_champ *tmp;
	char *s;

	if (!(tmp = (t_champ*)malloc(sizeof(t_champ))))
		ft_errors("ERROR : Error malloc", 1, 0);
	if (env->champ_start == NULL)
		env->champ_start = tmp;
	tmp->nb_champ = -nb;
	s = get_champ_file(file, width);
	tmp->width = width;
	tmp->name = ft_strsub(s, 4, PROG_NAME_LENGTH);
	tmp->comment = ft_strsub(s, 12 + PROG_NAME_LENGTH, COMMENT_LENGTH);
	tmp->code = my_strsub(s, COMMENT_NAME_MAGIC, width);
	tmp->next = NULL;
	if (env->champ_end != NULL)
		env->champ_end->next = tmp;
	env->champ_end = tmp;
}

char		*get_champ_file(char *file, int width)
{
	int fd;
	char buf[COMMENT_NAME_MAGIC + width];
	int i;
	int ret;
	char *s;


	i = -1;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_errors("ERROR : Fail open.", 1, 0);
	ret = read(fd, buf, COMMENT_NAME_MAGIC + width);
	if (!(s = (char*)malloc(sizeof(char) * COMMENT_NAME_MAGIC + width)))
		ft_errors("ERROR : malloc.", 1, 0);
	while (++i <= COMMENT_NAME_MAGIC + width)
	{
		//ft_printf("%d -> %x -> %c \n", i, (unsigned char)buf[i], buf[i]);
		s[i] = buf[i];
	}
	return (s);
}
