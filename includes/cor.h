/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:47:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/29 16:00:55 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <ncurses.h>

# define OPT_STRING "n"
# define COMMENT_NAME_MAGIC		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

typedef struct		s_inst
{
	char			opc;
	unsigned char			odc;
	unsigned int	*arg;
}					t_inst;

typedef struct		s_proc
{
	int				index;
	int				pos;
	int				pc;
	int				carry;
	int				r[REG_NUMBER];
	int				wait_cycle;
	t_inst			inst;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_champ
{
	char			*name;
	char			*comment;
	char			*code;
	int				width;
	int				nb_live;
	int				last_cycle_live;
	int				nb_champ;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_curse
{
	WINDOW			*principal;
	WINDOW			*secondary_1;
	WINDOW			*secondary_2;
	int				key;
}					t_curse;

typedef struct		s_env
{
	t_curse			curse;
	unsigned char	mem[MEM_SIZE];
	int				nb_cycle;
	int				nb_cycle_max;
	int				opt;
	int				nb_player;
	int				champ_in_life;
	int				proc_in_life;
	int				nb_proc;
	t_champ			*champ_start;
	t_champ			*champ_end;
	t_proc			*proc_start;
}					t_env;

typedef struct		s_op
{
	char			*name;
	int				nb_arg;
	t_arg_type		i[3];
	int				op_code;
	int				wait_before_exe;
	char			*description;
	int				codage_code;
	int				carry;
	int				label_size;
}					t_op;

/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char o, int opt);

/*
** Ncurses :
*/

void 				init_ncurses(t_env *e);

/*
** Champ :
*/

char				*get_champ_file(char *file, int width);
void				add_to_champ_lst(t_env *env, int nb, int width, char *file);
int					is_champ(char *s);

/*
** Processus :
*/

void				new_processus(t_env *e, int nb, int pos);
int					is_prog_pos(t_proc *start, int x, int y);

/*
** Game :
*/

void				game_loop(t_env *e);

/*
** Memory :
*/

void				insert_in_memory(t_env *e);
void				print_memory(t_env *e, unsigned char *s, t_proc *start);

/*
** Initialisation :
*/

void				init_cor(t_env *e, char **av);
void				init_env(t_env *e);

/*
** Print :
*/

int					print_help(void);

#endif
