/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:46:57 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/26 15:24:24 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int main(int ac, char **av)
{
	t_env e;

	if (ac < 2)
	{
		print_help();
		ft_errors("ERROR : invalide arguments.");
	}
}
