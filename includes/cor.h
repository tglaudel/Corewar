/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:47:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/03 13:01:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <ncurses.h>

# define OPT_STRING "nvd"
# define COMMENT_NAME_MAGIC		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define VERBOSE_LIVE 1
# define VERBOSE_CYCLE 2
# define VERBOSE_OP 4
# define VERBOSE_DIE 8
# define VERBOSE_PC 16
# define VERBOSE_DEBUG 32
# define BASE_HEXA "0123456789abcdef"

typedef struct		s_inst
{
	char			opc;
	unsigned char	odc;
	unsigned int	arg[3];
}					t_inst;

typedef struct		s_proc
{
	int				index;
	int				pos;
	int				pc;
	int				carry;
	int				r[REG_NUMBER];
	int				wait_cycle;
	int				live_exec;
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
	int				opt;
	int				verbose;
	unsigned char	mem[MEM_SIZE];
	int				nb_cycle;
	int				nb_cycle_max;
	int				nb_champ;
	int				nb_proc;
	int				c_to_die;
	int				nb_check_td;
	int				global_live;
	t_champ			*champ_start;
	t_champ			*champ_end;
	t_proc			*proc_start;
	t_curse			curse;
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
	int				dir_size;
	int				ind_size;
}					t_op;

extern t_op g_op_tab[17];

/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char o, int opt);
int					get_verbose(char **av);
int					get_ncycle(char **av);

/*
** Ncurses :
*/

void				init_ncurses(t_env *e);
void				init_ncurses2(void);

/*
** Champ :
*/

void				add_to_champ_lst(t_env *env, int nb, int width, char *file);
int					is_champ(char *s);

/*
** Processus :
*/

void				new_processus(t_env *e, int nb, int pos, t_proc *papa);
int					is_prog_pos(t_proc *start, int x, int y);
void				check_proc_cycle(t_env *e);

/*
** Game :
*/

void				game_loop(t_env *e);
unsigned int		ind_to_int(unsigned char *mem, int pos);
unsigned int		dir_to_int(unsigned char *mem, int pos);
int					have_odc_arg(int a, unsigned char *mem, t_proc *proc,\
					int i);
int					parsing_instruction(t_proc *proc, unsigned char *mem);
int					parsing_argument(t_proc *proc, unsigned char *mem, int i);

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
void				re_init_proc(t_proc *start);
void				init_proc(t_proc *proc);
/*
** OP :
*/

int					live(t_env *e, t_proc *proc);//		1
int					ld(t_env *e, t_proc *proc);//		2
int					zjmp(t_env *e, t_proc *proc);//		9

/*
** Print :
*/

int					print_help(void);
void				print_board(t_env *env);
//void				print_op(t_proc *proc, char *function);
void				print_processus_debug(t_proc *start, int nb_cycle);

#endif
