/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:25:26 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/22 18:32:01 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define OPT_STRING "av"

typedef struct		s_arg
{
	char			*data;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_env
{
	int				opt;
	header_t		cor;
}					t_env;

/*
** Options & env :
*/

int				get_opt(char **av, char *l_opt);
int				have_opt(char *l_opt, char o, int opt);

/*
** Gets :
*/

void			get_args(char **av, t_env *e);

/*
** Check :
*/

int 			is_good_format(char *s);

/*
** Utils :
*/

int			len_tab(char **s);


#endif
