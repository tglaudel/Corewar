/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 11:07:29 by tglaudel          #+#    #+#             */
/*   Updated: 2016/04/29 18:58:12 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 2},
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

void		print_op(t_proc *proc, int i)
{
	if (op_tab[i].nb_arg == 1)
		ft_printf("P %5d| %s %d\n", proc->index, op_tab[i].name,\
		proc->inst.arg[0]);
	else if (op_tab[i].nb_arg == 2)
		ft_printf("P %5d| %s %d %d\n", proc->index, op_tab[i].name,\
		proc->inst.arg[0], proc->inst.arg[1]);
	else if (op_tab[i].nb_arg == 3)
		ft_printf("P %5d| %s %d %d %d\n", proc->index, op_tab[i].name,\
		proc->inst.arg[0], proc->inst.arg[1], proc->inst.arg[2]);
}

unsigned int			dir_to_int(unsigned char *mem, int pos)
{
	unsigned int dir;

	// ft_printf("%3.2x", mem[pos]);
	// ft_printf("%3.2x \n", mem[pos + 1]);
	dir = 0;
	dir = (dir | mem[pos]) << 8;
	dir = dir | mem[(pos + 1) % MEM_SIZE];

	return (dir);
}

unsigned int			ind_to_int(unsigned char *mem, int pos)
{
	unsigned int ind;

	// ft_printf("debut %3.2x", mem[pos]);
	// ft_printf("%3.2x", mem[pos + 1]);
	// ft_printf("%3.2x", mem[pos + 2]);
	// ft_printf("%3.2x fin\n", mem[pos + 3]);
	ind = 0;
	ind = (ind | mem[pos]) << 8;
	ind = (ind | mem[(pos + 1) % MEM_SIZE]) << 8;
	ind = (ind | mem[(pos + 2) % MEM_SIZE]) << 8;
	ind = ind | mem[(pos + 3) % MEM_SIZE];
	return (ind);
}

int				have_odc_arg(int a, unsigned char *mem, t_proc *proc, int i)
{
	int pos_mem;

	pos_mem = 2;
	while (++a < op_tab[i].nb_arg)
	{
		if ((proc->inst.odc >> (6 - a * 2) & IND_CODE) == IND_CODE ||\
		(proc->inst.odc >> (6 - a * 2) & DIR_CODE) == DIR_CODE)
		{
			if (op_tab[i].label_size == 4)
			{
				proc->inst.arg[a] = ind_to_int(mem, proc->pos + pos_mem);
				pos_mem += 2;
			}
			else if (op_tab[i].label_size == 2)
				proc->inst.arg[a] = dir_to_int(mem, proc->pos + pos_mem);
			pos_mem += 2;
		}
		else if ((proc->inst.odc >> (6 - a * 2) & REG_CODE) == REG_CODE)
		{
			proc->inst.arg[a] = proc->r[(int)mem[proc->pos + pos_mem] - 1];
			++pos_mem;
		}
	}
	return (pos_mem);
}

int				parsing_argument(t_proc *proc, unsigned char *mem, int i)
{
	int a;
	int pos_mem;

	pos_mem = 1;
	a = -1;
	if (proc->inst.odc)
	{
		if (proc->inst.opc == 15)
			proc->inst.arg[0] = mem[(proc->pos + 2) % MEM_SIZE];
		else
			return (have_odc_arg(a, mem, proc, i));
	}
	else
	{
		if (proc->inst.opc == 1)
		{
			proc->inst.arg[0] = ind_to_int(mem, proc->pos + pos_mem);
			pos_mem += 4;
		}
		else if (proc->inst.opc == 12 || proc->inst.opc == 15 || proc->inst.opc == 9)
		{
			proc->inst.arg[0] = dir_to_int(mem, proc->pos + pos_mem);
			pos_mem += 2;
		}
		return (pos_mem);
	}
	return (0);
}

int			parsing_instruction(t_proc *proc, unsigned char *mem)
{
	int i;
	int size;

	i = -1;
	while (op_tab[++i].op_code != 0)
	{
		if (op_tab[i].op_code == mem[proc->pos])
		{
			proc->inst.opc = (int)mem[proc->pos];
			if (op_tab[i].codage_code == 1)
				proc->inst.odc = mem[(proc->pos + 1) % MEM_SIZE];
			if ((size = parsing_argument(proc, mem, i)))
			{
				proc->wait_cycle = op_tab[i].wait_before_exe - 1;
				return (size);
			}
			else
				return (-1);
		}
	}
	return (-1);
}

static int 		define_instruction(t_env *e, t_proc *proc, unsigned char *mem)
{
	int size;

	if ((size = parsing_instruction(proc, mem)) == -1)
	{
		proc->pos = ++proc->pos % MEM_SIZE;
	}
	else
	{
		if (e->verbose & VERBOSE_OP)
			print_op(proc, proc->inst.opc - 1);
		return (size);
	}
	return (-1);
}

static void		exe_instruction(t_proc *proc)
{
	proc->pos = proc->pc;
	proc->pc = 0;
	proc->inst.opc = 0;
	proc->inst.odc = 0;
	proc->inst.arg[0] = 0;
	proc->inst.arg[1] = 0;
	proc->inst.arg[2] = 0;
	proc->r[13] = 5;
}

static void		proc_loop(t_env *e)
{
	t_proc *proc;
	int size;

	proc = e->proc_start;
	while (proc)
	{
		size = -1;
		if (proc->wait_cycle > 0)
			--proc->wait_cycle;
		else if (proc->wait_cycle == 0 && proc->inst.opc != 0)
		{
			if (proc->inst.opc == 12)
				new_processus(e, e->nb_proc, proc->pos + 5);
			exe_instruction(proc);
			if ((size = define_instruction(e, proc, e->mem)))
				proc->pc = (proc->pos + size) % MEM_SIZE;
		}
		else if ((size = define_instruction(e, proc, e->mem)))
		{
			proc->pc = (proc->pos + size) % MEM_SIZE;
		}
		// ++proc->pos;
		// if (proc->pos == MEM_SIZE)
		// 	proc->pos = 0;
		proc = proc->next;
	}
}

void		game_loop(t_env *e)
{
	while (e->champ_in_life > 0 && e->proc_in_life > 0 &&\
	e->nb_cycle < e->nb_cycle_max)
	{
	//	if ((e->curse.key = getch()) == 27)
	//		return ;
			proc_loop(e);
			++e->nb_cycle;
			if (e->verbose & VERBOSE_CYCLE)
				ft_printf("It is now cycle %d -> %d \n", e->nb_cycle, e->nb_proc);
			//system("clear");
			//print_memory(e, e->mem, e->proc_start);
			//usleep(25000);
	}
}
