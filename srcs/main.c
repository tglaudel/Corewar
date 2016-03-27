/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:24:56 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/27 16:06:41 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

int		invert(int n)
{
	unsigned char tmp1;
	unsigned char tmp2;
	unsigned char tmp3;
	unsigned char tmp4;

	tmp1 = n >> 24;
	tmp2 = n >> 16;
	tmp3 = n >> 8;
	tmp4 = n;
	n = tmp4 << 8;
	n = (n | tmp3) << 8;
	n = (n | tmp2) << 8;
	n = n | tmp1;
	return (n);
}

static void		init_env(t_env *env)
{
	env->opt = 0;
	env->label_s = NULL;
	env->label_e = NULL;
	env->cmd_s = NULL;
	env->cmd_e = NULL;
	env->pos_rel = 0;
	env->label_c = NULL;
	env->cor.magic = invert(COREWAR_EXEC_MAGIC);
	ft_bzero(env->cor.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(env->cor.comment, COMMENT_LENGTH + 1);
}

int				main(int ac, char **av)
{
	t_env	e;

	if (ac < 2)
		ft_errors("ERROR : No args.", 1, 0);
	init_env(&e);
	e.opt = get_opt(&av[1], OPT_STRING);
	get_args(&av[1], &e);
	convert_to_octet(e.cmd_s);
	if (have_opt('d', e.opt))
		print_opt_d(&e);
	if (have_opt('o', e.opt))
		print_opt_o(&e);
	create_file(&e.cor, e.cmd_s, &e);
	return (0);
}
