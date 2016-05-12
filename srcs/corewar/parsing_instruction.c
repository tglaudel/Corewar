/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 09:46:44 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/12 21:53:10 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int				define_opc(t_proc *proc, unsigned char *mem)
{
	int i;

	i = -1;
	while (g_op_tab[++i].op_code != 0)
	{
		if (g_op_tab[i].op_code == mem[proc->pos])
		{
			proc->wait_cycle = g_op_tab[i].wait_before_exe - 1;
			proc->inst.opc = g_op_tab[i].op_code;
			return (1);
		}
	}
	return (0);
}

int				error_odc(t_proc *proc, int i)
{
	int n;
	int size;

	size = 2;
	n = -1;
	while (++n < g_op_tab[i].nb_arg)
	{
		if (((proc->inst.odc >> (6 - n * 2)) & IND_CODE) == IND_CODE)
			size += g_op_tab[i].ind_size;
		else if (((proc->inst.odc >> (6 - n * 2)) & DIR_CODE) == DIR_CODE)
			size += g_op_tab[i].dir_size;
		else if (((proc->inst.odc >> (6 - n * 2)) & REG_CODE) == REG_CODE)
			++size;
	}
	return (size);
}

int				have_odc_arg(int a, unsigned char *mem, t_proc *proc, int i)
{
	int pos_mem;

	pos_mem = 2;
	while (++a < g_op_tab[i].nb_arg)
	{
		if ((proc->inst.odc >> (6 - a * 2) & IND_CODE) == IND_CODE)
		{
			if (g_op_tab[i].ind_size == 4)
				pos_mem += pre_int(proc, mem, proc->pos + pos_mem, a);
			else if (g_op_tab[i].ind_size == 2)
				proc->inst.arg[a] = dir_to_int(mem, proc->pos + pos_mem);
			pos_mem += 2;
		}
		else if ((proc->inst.odc >> (6 - a * 2) & DIR_CODE) == DIR_CODE)
		{
			if (g_op_tab[i].dir_size == 4)
				pos_mem += pre_int(proc, mem, proc->pos + pos_mem, a);
			else if (g_op_tab[i].dir_size == 2)
				proc->inst.arg[a] = dir_to_int(mem, proc->pos + pos_mem);
			pos_mem += 2;
		}
		else if ((proc->inst.odc >> (6 - a * 2) & REG_CODE) == REG_CODE)
			proc->inst.arg[a] = (int)mem[(proc->pos + pos_mem++) % MEM_SIZE];
	}
	return (pos_mem);
}

int				parsing_argument(t_proc *p, unsigned char *mem, int i)
{
	int a;
	int pos_mem;

	pos_mem = 1;
	a = -1;
	if (p->inst.odc)
	{
		if (p->inst.opc == 15)
			p->inst.arg[0] = mem[(p->pos + 2) % MEM_SIZE];
		else
			return (have_odc_arg(a, mem, p, i));
	}
	else if (p->inst.opc == 1)
	{
		p->inst.arg[0] = ind_to_int(mem, p->pos + pos_mem);
		pos_mem += 4;
	}
	else if (p->inst.opc == 12 || p->inst.opc == 15 || p->inst.opc == 9)
	{
		p->inst.arg[0] = dir_to_int(mem, p->pos + pos_mem);
		pos_mem += 2;
	}
	return (pos_mem == 1 ? 0 : pos_mem);
}

int				check_odc(t_proc *proc, int i)
{
	int n;

	n = -1;
	while (g_codage_tab[i].odc[++n] != 0)
		if (proc->inst.odc == g_codage_tab[i].odc[n])
			return (1);
	return (0);
}
