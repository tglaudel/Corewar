/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:25:26 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/26 14:52:39 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define OPT_STRING "do"
# define MASK_CHAR	0xff
# define MASK_DCHAR	0xff00
# define MASK_TCHAR	0xff0000
# define MASK_INT	0xff000000

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
	int				pos_oct;
	int				size;
	t_arg			**tab;
	char			*label;
	struct s_cmd	*next;
	unsigned char	*octet;
}					t_cmd;

typedef struct		s_label
{
	char			*name;
	int				pos;
	t_cmd			*cmd;
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
	int				pos_rel; // position relative de la cmd;
	char			*label_c; // label en cours, variable tmp;
}					t_env;

/*
** Options & env :
*/

int					get_opt(char **av, char *l_opt);
int					have_opt(char o, int opt);

/*
** Gets :
*/

void				get_args(char **av, t_env *e);
char				create_odc(int opc, t_arg **tab);

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

/*
** Conversion:
*/

void				convert_to_octet(t_cmd *start);

/*
** Utils & print:
*/

int					in_str(char c, char *s);
int					len_tab(char **s);
int					is_all_num(char *s);
void				print_label(t_label *start);
void				print_cmd(t_cmd *start);
void				print_opt_d(t_env *e);
void				print_opt_o(t_env *e);
char				*format_str(char *s);

#endif
