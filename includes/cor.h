/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:47:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/26 18:45:22 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/includes/libft.h"
# include "op.h"

# define OPT_STRING ""
# define COMMENT_NAME_MAGIC		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)


typedef struct		s_champ
{
	char			*name;
	char			*comment;
	char			*code;
	int				width;
	int				reg[16];
	int				pc;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_env
{
	char			mem[MEM_SIZE];
	int				opt;
	int				nb_player;
	t_champ			*champ_start;
}					t_env;

/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char o, int opt);

/*
**
*/

char				*get_champ_file(char *file, int width);
int					is_champ(char *s);

/*
**
*/

int					print_help(void);

#endif
