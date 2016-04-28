/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/28 14:50:21 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

// t_op    op_tab[17] =
// {
// 	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
// 	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4},
// 	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 0},
// 	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0},
// 	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 0},
// 	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
// 		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4},
// 	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
// 		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4},
// 	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
// 		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4},
// 	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2},
// 	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
// 		"load index", 1, 1, 2},
// 	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
// 		"store index", 1, 1, 2},
// 	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2},
// 	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4},
// 	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
// 		"long load index", 1, 1, 2},
// 	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2},
// 	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
// 	{0, 0, {0}, 0, 0, 0, 0, 0}
// };
//
// int			parsing_argument(t_proc *proc, char *mem, int i)
// {
// 	int arg;
//
// 	arg = 3;
// 	if (proc->odc)
// 	{
// 		if (proc->opc == 15)
// 			proc->inst[0] = mem[(proc->pos + 2) % MEM_SIZE];
// 		else
// 		{
// 			proc->odc = proc->odc >> 2;
// 			while (--arg)
// 			{
// 				if (proc->odc & IND_CODE)
// 				{
//
// 				}
// 				else if (proc->odc & DIR_CODE)
// 				{
//
// 				}
// 				else if (proc->odc & REG_CODE)
// 				{
//
// 				}
// 				else
// 					proc->odc = proc->odc >> 2;
// 			}
// 		}
// 	}
// 	else
// 	{
//
// 	}
//
// }
//
// int			parsing_instruction(t_proc *proc, char *mem)
// {
// 	int i;
//
// 	i = -1;
// 	while (op_tab[++i].opc != 0)
// 	{
// 		if (op_tab[i].opc == mem[proc->pos])
// 		{
// 			proc->opc = (int)mem[proc->pos];
// 			if (op_tab[i].codage_code == 1)
// 				proc->odc = mem[(proc->pos + 1) % MEM_SIZE];
// 			return (parsing_argument(proc, mem));
// 		}
// 	}
// 	return (-1)
// }
//
// void		define_instruction(t_proc *proc, char *mem)
// {
// 	if (parsing_instruction(proc, mem) == -1)
// 	{
//
// 	}
// 	else
// 	{
//
// 	}
// }

static void		proc_loop(int nb_cycle, t_proc *start, char *mem)
{
	t_proc *tmp;

	tmp = start;
	(void)nb_cycle;
	(void)mem;
	while (tmp)
	{
		// if (tmp->wait_cycle > 0)
		// 	--tmp->wait_cycle;
		// else if (tmp->wait_cycle == 0 && tmp->inst.opc != 0)
		// 	if (tmp->inst.opc != 0)
		// 		exe_instruction(tmp, mem);
		// else
		// 	define_instruction(tmp, mem);
		++tmp->pos;
		if (tmp->pos == MEM_SIZE)
			tmp->pos = 0;
		tmp = tmp->next;
	}
}

void		game_loop(t_env *e)
{
	while (e->champ_in_life > 0 && e->proc_in_life > 0 &&\
	e->nb_cycle < e->nb_cycle_max)
	{
		++e->nb_cycle;
		proc_loop(e->nb_cycle, e->proc_start, e->mem);
		system("clear");
		print_memory(e->mem, e->proc_start);
		usleep(20000);
	}
}
