/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:25:26 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/23 15:06:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define OPT_STRING "av"

typedef struct		s_label
{
	char			*name;
	int				pos;
	struct s_label	*next;
}					t_label;

typedef struct		s_env
{
	int				opt;
	t_header		cor;
	t_label			*label_s;
	t_label			*label_e;
}					t_env;


/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char *l_opt, char o, int opt);

/*
** Gets :
*/

void				get_args(char **av, t_env *e);

/*
** Check & parsing:
*/

int					is_good_format(char *s, t_header *cor, t_env *e);
int					is_comment(char *s, t_header *cor);
int					is_label(char *s, t_env *e);
int					is_cmd(char *s, t_env *e);

/*
** Utils & print:
*/

int					in_str(char c, char *s);
int					len_tab(char **s);
void				print_label(t_label *start);

#endif
