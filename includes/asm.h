/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:25:26 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/13 21:18:02 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define OPT_STRING "dofh"

typedef struct		s_arg
{
	char			type;
	char			size;
	char			*arg;
}					t_arg;

typedef struct		s_cmd
{
	char			opc;
	unsigned char	odc;
	unsigned int	pos_oct;
	int				size;
	t_arg			**tab;
	struct s_cmd	*next;
	unsigned char	*octet;
}					t_cmd;

typedef struct		s_label
{
	char			*name;
	unsigned int	pos;
	struct s_label	*next;
}					t_label;

typedef struct		s_env
{
	int				opt;
	t_header		cor;
	t_label			*label_s;
	t_label			*label_e;
	t_cmd			*cmd_s;
	t_cmd			*cmd_e;
	char			*name;
	int				pos_rel;
}					t_env;

typedef struct		s_op
{
	char			*name;
	int				nb_arg;
	t_arg_type		i[3];
	int				op_code;
}					t_op;

/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char o, int opt);

/*
** Gets :
*/

int					get_args(char *av, t_env *e);
char				create_odc(int opc, t_arg **tab);
int					get_size(t_arg **tab, int odc);
t_arg				**get_cmd_arg(char *s, int opc, int i);
int					format_cmd_size(char type, char *s, int n, int opc);
int					format_cmd_arg(char *s);
t_cmd				*new_cmd(void);
void				add_cmd(t_env *e, char *s, int n);

/*
** Check & parsing:
*/

int					is_good_format(char *s, t_header *cor, t_env *e);
int					is_comment(char *s, t_header *cor);
int					is_label(char *s, t_env *e);
int					is_cmd(char *s, t_env *e);
int					is_dir(char *s);
int					is_reg(char *s);
int					is_ind(char *s);
int					check_cmd(char *s, int nb_arg, int op);

/*
** Conversion:
*/

void				convert_to_octet(t_cmd *start, t_label *lab);
int					invert(int n);

/*
** Utils & print:
*/

int					in_str(char c, char *s);
int					len_tab(char **s);
int					is_all_num(char *s);
void				print_label(t_label *start);
void				print_cmd(t_cmd *start);
void				print_opt_d(t_env *e, int i);
void				print_opt_o(t_env *e);
int					print_help(void);
char				*format_str(char *s);
void				create_file(t_header *cor, t_cmd *cmd, t_env *e);
void				free_all(t_env *e);
void				free_label(t_label *label);
void				free_cmd(t_cmd *cmd);
void				free_tab(char **s);

#endif
