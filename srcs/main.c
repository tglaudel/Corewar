/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 11:24:56 by tglaudel          #+#    #+#             */
/*   Updated: 2016/03/24 12:05:14 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"

static void		init_env(t_env *env)
{
	env->opt = 0;
}

int				main(int ac, char **av)
{
	t_env	e;

	if (ac < 2)
		ft_errors("ERROR : No args.", 1, 0);
	init_env(&e);
	e.opt = get_opt(&av[1], OPT_STRING);
	get_args(&av[1], &e);
	ft_putendl(e.cor.prog_name);
	ft_putendl(e.cor.comment);
	print_label(e.label_s);
	return (0);
}
