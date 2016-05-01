/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:46:44 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/01 13:20:01 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int				have_odc_arg(int a, unsigned char *mem, t_proc *proc, int i)
{
	int pos_mem;

	pos_mem = 2;
	while (++a < g_op_tab[i].nb_arg)
	{
		if ((proc->inst.odc >> (6 - a * 2) & IND_CODE) == IND_CODE ||\
		(proc->inst.odc >> (6 - a * 2) & DIR_CODE) == DIR_CODE)
		{
			if (g_op_tab[i].label_size == 4)
			{
				proc->inst.arg[a] = ind_to_int(mem, proc->pos + pos_mem);
				pos_mem += 2;
			}
			else if (g_op_tab[i].label_size == 2)
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
	else if (proc->inst.opc == 1)
	{
		proc->inst.arg[0] = ind_to_int(mem, proc->pos + pos_mem);
		pos_mem += 4;
	}
	else if (proc->inst.opc == 12 || proc->inst.opc == 15 || proc->inst.opc == 9)
	{
		proc->inst.arg[0] = dir_to_int(mem, proc->pos + pos_mem);
		pos_mem += 2;
	}
	return (pos_mem == 1 ? 0 : pos_mem);
}

int			parsing_instruction(t_proc *proc, unsigned char *mem)
{
	int i;
	int size;

	i = -1;
	while (g_op_tab[++i].op_code != 0)
	{
		if (g_op_tab[i].op_code == mem[proc->pos])
		{
			proc->inst.opc = (int)mem[proc->pos];
			if (g_op_tab[i].codage_code == 1)
				proc->inst.odc = mem[(proc->pos + 1) % MEM_SIZE];
			if ((size = parsing_argument(proc, mem, i)))
			{
				proc->wait_cycle = g_op_tab[i].wait_before_exe - 1;
				return (size);
			}
			else
				return (-1);
		}
	}
	return (-1);
}
