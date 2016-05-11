/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:47:40 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/11 23:19:02 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <ncurses.h>

# define OPT_STRING "cvd"
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

typedef struct		s_env
{
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
	t_champ			*winner;
	t_champ			*champ_start;
	t_champ			*champ_end;
	t_proc			*proc_start;
	t_curse			curse;
}					t_env;

typedef int 		(*instruction)(t_env *e, t_proc *proc);

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
	instruction		f;
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

/*
** Ncurses :
*/

void				init_ncurses(t_env *e);
void				init_ncurses2(void);
void				ncurses_loop(t_env *e);

/*
** Champ :
*/

void				add_to_champ_lst(t_env *env, int nb, int width, char *file);
int					is_champ(char *s, t_env *e);
void				check_champ_cycle(t_env *e);

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
int					ind_to_int(unsigned char *mem, int pos);
short int			dir_to_int(unsigned char *mem, int pos);
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
int 				check_args(t_proc *proc, int i, int n);

int					live(t_env *e, t_proc *proc);//			1
int					ld(t_env *e, t_proc *proc);//			2
int					st(t_env *e, t_proc *proc);//			3
int					add(t_env *e, t_proc *proc);//			4
int					sub(t_env *e, t_proc *proc);//			5
int					and(t_env *e, t_proc *proc);//			6
int					or(t_env *e, t_proc *proc);//			7
int					xor(t_env *e, t_proc *proc);//			8
int					zjmp(t_env *e, t_proc *proc);//			9
int					ldi(t_env *e, t_proc *proc);//			10
int					sti(t_env *e, t_proc *proc);//			11
int					fork_cor(t_env *e, t_proc *proc);//		12
int					lld(t_env *e, t_proc *proc);//			13
int					lldi(t_env *e, t_proc *proc);//			14
int					lfork_cor(t_env *e, t_proc *proc);//	15
int					aff(t_env *e, t_proc *proc);//			16

/*
** Print :
*/

int					print_help(void);
void				print_board(t_env *env);
void				print_processus_debug(t_proc *start, int nb_cycle);
void				print_in_memory(t_env *e, int val, int pos, t_proc *proc);
void				print_processus(t_proc *start, t_env *e);
void 				print_instruction(t_proc * proc, int nb_arg, char *inst, int store);
void				print_adv(t_proc * proc, t_env *e, int bloque);

#endif
