/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 10:19:31 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 15:11:34 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

t_op    g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, 0, live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, 2, ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, 2, st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4, 2, add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 4, 2, sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, 2, and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, 2, or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, 2, xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, 0, zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2, 2, ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2, 2, sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, 0, fork_cor},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4, 2, lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2, 2, lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, 0, lfork_cor},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, 2, aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0, 0, 0}
};

t_od	g_codage_tab[17] =
{
	{1, {128, 0}},
	{2, {144, 208, 0}},
	{3, {112, 80, 0}},
	{4, {84, 0}},
	{5, {84, 0}},
	{6, {84, 116, 100, 212, 244, 228, 148, 180, 164, 0}},
	{7, {84, 116, 100, 212, 244, 228, 148, 180, 164, 0}},
	{8, {84, 116, 100, 212, 244, 228, 148, 180, 164, 0}},
	{9, {128, 0}},
	{10, {100, 84, 164, 148, 212, 228, 0}},
	{11, {84, 100, 116, 104, 120, 88, 0}},
	{12, {128, 0}},
	{13, {144, 208, 0}},
	{14, {100, 84, 164, 148, 212, 228, 0}},
	{15, {128, 0}},
	{16, {64, 0}},
	{0, {0}},
};
