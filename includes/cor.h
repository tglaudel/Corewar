/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:47:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/13 16:14:27 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <ncurses.h>

# define OPT_STRING "cvdn"
# define COMMENT_NAME_MAGIC		(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
# define BASE_HEXA "0123456789abcdef"
# define MUI 4294967295

# define VERBOSE_LIVE 1
# define VERBOSE_CYCLE 2
# define VERBOSE_OP 4
# define VERBOSE_DIE 8
# define VERBOSE_PC 16
# define VERBOSE_DEBUG 32

# define ABS(x) x > 0 ? x : -x

typedef struct		s_inst
{
	char			opc;
	unsigned char	odc;
	int				arg[3];
	int				size;
}					t_inst;

typedef struct		s_proc
{
	int				index;
	int				pos;
	int				pc;
	int				carry;
	int				*r;
	int				wait_cycle;
	int				live_exec;
	int				champ_color;
	char			exec;
	t_inst			inst;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_champ
{
	char			color;
	char			*name;
	char			*comment;
	char			*code;
	int				width;
	int				nb_live;
	int				pos;
	int				last_cycle_live;
	int				nb_champ;
	char			is_alive;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_curse
{
	WINDOW			*principal;
	WINDOW			*secondary_1;
	WINDOW			*secondary_2;
	int				key;
}					t_curse;

typedef struct		s_winner
{
	int				nb_win;
	char			*winner;
}					t_winner;

typedef struct		s_env
{
	int				c;
	int				test_n;
	int				v;
	int				n3;
	int				d;
	char			char_opt;
	char			*player;
	int				iplayer;
	int				opt;
	int				fd;
	int				width;
	int				verbose;
	unsigned char	mem[MEM_SIZE];
	char			col[MEM_SIZE];
	int				nb_cycle;
	int				nb_cycle_max;
	int				nb_champ;
	int				nb_proc;
	int				c_to_die;
	int				nb_check_td;
	int				global_live;
	int				nb_proc_in_life;
	int				speed;
	int				speed_mult;
	int				n;
	t_winner		winner;
	t_champ			*champ_start;
	t_champ			*champ_end;
	t_proc			*proc_start;
	t_curse			curse;
}					t_env;

typedef int			(*t_instruction)(t_env *e, t_proc *proc);

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
	t_instruction	f;
}					t_op;

typedef struct		s_od
{
	int				op_code;
	unsigned char	odc[10];
}					t_od;

extern t_op g_op_tab[17];
extern t_od g_codage_tab[17];

/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char o, int opt);
int					get_verbose(char **av);
int					get_ncycle(char **av);
void				free_all(t_env *e);
void				free_processus(t_proc *proc);
void				test_option(t_env *e, char *s);
int					test_param_opt(t_env *e, char *av);
void				show_start(t_env *e);
void				last_check(t_env *e);

/*
** Ncurses :
*/

void				init_ncurses(void);
void				ncurses_loop(t_env *e);
void				ncurses_winner(t_env *e);
void				print_champ(t_env *e);
void				print_info(t_env *e);
void				print_processus(t_proc *start, t_env *e);
void				wait_cycle(t_env *e);
char				get_move(void);
void				change_speed(t_env *e, int n);
void				init_color_pair(void);
void				print_boarder_second(void);
void				print_boarder_principal(void);

/*
** Champ :
*/

void				add_to_champ_lst(t_env *env, int nb, int width, char *file);
int					is_champ(char *s, t_env *e);
void				check_champ_cycle(t_env *e);

/*
** Processus :
*/

void				new_processus(t_env *e, t_champ *champ, int pos,\
					t_proc *papa);
int					is_prog_pos(t_proc *start, int x, int y);
void				check_proc_cycle(t_env *e);

/*
** Game :
*/

void				game_loop(t_env *e);
int					ind_to_int(unsigned char *mem, int pos);
short int			dir_to_int(unsigned char *mem, int pos);
int					pre_int(t_proc *proc, unsigned char *mem, int n, int a);
int					have_odc_arg(int a, unsigned char *mem, t_proc *proc,\
					int i);
int					check_odc(t_proc *proc, int i);
int					parsing_argument(t_proc *proc, unsigned char *mem, int i);
int					error_odc(t_proc *proc, int i);
int					define_opc(t_proc *proc, unsigned char *mem);

/*
** Memory :
*/

void				insert_in_memory(t_env *e);
void				print_memory(unsigned char *s);

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

int					recup_value(unsigned char *mem, t_proc *proc, int i, int n);
int					check_args(t_proc *proc, int i, int n);

int					live(t_env *e, t_proc *proc);
int					ld(t_env *e, t_proc *proc);
int					st(t_env *e, t_proc *proc);
int					add(t_env *e, t_proc *proc);
int					sub(t_env *e, t_proc *proc);
int					and(t_env *e, t_proc *proc);
int					or(t_env *e, t_proc *proc);
int					xor(t_env *e, t_proc *proc);
int					zjmp(t_env *e, t_proc *proc);
int					ldi(t_env *e, t_proc *proc);
int					sti(t_env *e, t_proc *proc);
int					fork_cor(t_env *e, t_proc *proc);
int					lld(t_env *e, t_proc *proc);
int					lldi(t_env *e, t_proc *proc);
int					lfork_cor(t_env *e, t_proc *proc);
int					aff(t_env *e, t_proc *proc);

/*
** Print :
*/

int					print_help(void);
void				print_board(t_env *env);
void				print_processus_debug(t_proc *start, int nb_cycle);
void				print_in_memory(t_env *e, int val, int pos, t_proc *proc);
void				print_instruction(t_proc *proc, int nb_arg, char *inst,\
					int store);
void				print_adv(t_proc *proc, t_env *e, int bloque);

#endif
