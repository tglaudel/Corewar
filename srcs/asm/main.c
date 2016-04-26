/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:24:56 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/29 12:01:45 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static void		init_env(t_env *env)
{
	env->label_s = NULL;
	env->label_e = NULL;
	env->cmd_s = NULL;
	env->cmd_e = NULL;
	env->pos_rel = 0;
	env->cor.magic = invert(COREWAR_EXEC_MAGIC);
	ft_bzero(env->cor.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(env->cor.comment, COMMENT_LENGTH + 1);
}

static int		asm_loop(t_env *e, char *av)
{
	init_env(e);
	if (get_args(av, e) == -1)
		return (0);
	convert_to_octet(e->cmd_s, e->label_s);
	if (have_opt('d', e->opt))
		print_opt_d(e, 0);
	if (have_opt('o', e->opt))
		print_opt_o(e);
	if ((have_opt('o', e->opt) || have_opt('d', e->opt)) && !have_opt('f',\
	e->opt))
		return (0);
	create_file(&e->cor, e->cmd_s, e);
	free_all(e);
	return (1);
}

int				main(int ac, char **av)
{
	t_env	e;
	int		i;

	i = 0;
	if (ac < 2)
	{
		print_help();
		ft_errors("ERROR : No args.", 1, 0);
	}
	e.opt = get_opt(&av[1], OPT_STRING);
	if (have_opt('h', e.opt))
		return (print_help());
	while (av[++i])
		asm_loop(&e, av[i]);
	return (0);
}
