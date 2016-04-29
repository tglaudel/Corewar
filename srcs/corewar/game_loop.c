/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgiraud <fgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/29 15:35:48 by fgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};

unsigned int			dir_to_int(char *mem, int pos) // 2
{
	unsigned int dir;

	// ft_putendl("salut je rentre ici");
	dir = 0;
	dir = (dir | mem[pos]) << 8;
	dir = dir | mem[(pos + 1) % MEM_SIZE];

	return (dir);
}

unsigned int			ind_to_int(char *mem, int pos) // 4
{
	unsigned int ind;

	ind = 0;
	ind = (ind | mem[pos]) << 8;
	ind = (ind | mem[(pos + 1) % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 2) % MEM_SIZE]) << 8;
	ind = ind | mem[(pos + 3) % MEM_SIZE];
	return (ind);
}

int				parsing_argument(t_proc *proc, char *mem)
{
	int a;
	int pos_mem;
	int i = -1;

	pos_mem = 1;
	a = -1;
	while (++i < 10)
	{
		// ft_printf("%3.2x", mem[proc->pos + i]);
	}
	// ft_putchar('\n');
	if (proc->inst.odc)
	{
		++pos_mem;
		if (proc->inst.opc == 15)
			proc->inst.arg[0] = mem[(proc->pos + 2) % MEM_SIZE];
		else
		{
			while (++a < 3)
			{
				if ((proc->inst.odc >> (a * 2 + 2) & IND_CODE) == IND_CODE)
				{
					proc->inst.arg[a] = ind_to_int(mem, proc->pos);
					pos_mem += 4;
				}
				else if ((proc->inst.odc >> (a * 2 + 2) & DIR_CODE) == DIR_CODE)
				{
					proc->inst.arg[a] = dir_to_int(mem, proc->pos);
					pos_mem += 2;
				}
				else if ((proc->inst.odc >> (a * 2 + 2) & REG_CODE) == REG_CODE)
				{
					proc->inst.arg[a] = mem[proc->pos];
					pos_mem += 1;
				}
			}
		}
		return (1);
	}
	return (0);
}

int			parsing_instruction(t_proc *proc, char *mem)
{
	int i;

	i = -1;
	while (op_tab[++i].op_code != 0)
	{
		if (op_tab[i].op_code == mem[proc->pos])
		{
			proc->inst.opc = (int)mem[proc->pos];
			if (op_tab[i].codage_code == 1)
				proc->inst.odc = mem[(proc->pos + 1) % MEM_SIZE];
			if (parsing_argument(proc, mem))
			{
				proc->wait_cycle = op_tab[i].wait_before_exe - 1;
				return (1);
			}
			else
				return (0);
		}
	}
	return (-1);
}

void		define_instruction(t_proc *proc, char *mem)
{
	if (parsing_instruction(proc, mem) == -1)
	{
		ft_printf("error\n");
	}
	else
	{
		// ft_printf("P %d | opc : %d, arg1 : %d, arg2 : %d, arg3 : %d\n",
		// proc->index, proc->inst.opc, proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2]);
	}
}

static void		proc_loop(int nb_cycle, t_proc *start, char *mem)
{
	t_proc *tmp;

	tmp = start;
	(void)nb_cycle;
	(void)mem;
	while (tmp)
	{
		if (tmp->wait_cycle > 0)
			--tmp->wait_cycle;
		else if (tmp->wait_cycle == 0 && tmp->inst.opc != 0)
		{
			if (tmp->inst.opc != 0)
			{

			}
				// ft_printf("C'est ok !");
				//exe_instruction(tmp, mem);
		}
		else
			define_instruction(tmp, mem);
		// ++tmp->pos;
		// if (tmp->pos == MEM_SIZE)
		// 	tmp->pos = 0;
		tmp = tmp->next;
	}
}

void		game_loop(t_env *e)
{
	while (e->champ_in_life > 0 && e->proc_in_life > 0 &&\
	e->nb_cycle < e->nb_cycle_max)
	{
		if ((e->curse.key = getch()) == 27)
			return ;
			proc_loop(e->nb_cycle, e->proc_start, e->mem);
			++e->nb_cycle;
			// ft_printf("It is now cycle %d\n", e->nb_cycle);
			//system("clear");
			print_memory(e, e->mem, e->proc_start);
			//usleep(20000);
			wrefresh(e->curse.principal);
	}
}
