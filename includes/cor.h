/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:47:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/27 18:33:10 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/includes/libft.h"
# include "op.h"

# define OPT_STRING "n"
# define COMMENT_NAME_MAGIC		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

typedef struct		s_proc
{
	int				pc;
	//tab registre;
	int				wait_cycle; // attente avant execution instruction.
	char			*inst; // instruction.
}					t_proc;

typedef struct		s_champ
{
	char			*name;
	char			*comment;
	char			*code;
	int				width;
	int				nb_live;
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
** Ncurses :
*/

int 				init_ncurses(void);

/*
**
*/

char				*get_champ_file(char *file, int width);
void				add_to_champ_lst(t_env *env, int nb, int width, char *file);
int					is_champ(char *s);

/*
**
*/

void				insert_in_memory(t_env *e);
void				print_memory(char *s);

/*
**
*/

void				init_cor(t_env *e, char **av);
void				init_env(t_env *e);

/*
**
*/

int					print_help(void);

#endif
