/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:00:08 by tglaudel          #+#    #+#             */
/*   Updated: 2016/05/10 10:30:55 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

void print_processus_debug(t_proc *start, int nb_cycle)
{
	t_proc *proc;

	proc = start;
	ft_putstr("proc list : ");
	while (proc)
	{
		ft_putnbr(proc->index);
		ft_putchar(' ');
		proc = proc->next;
	}
	ft_printf(" ->cycle : %d", nb_cycle);
	ft_putchar('\n');
}

void print_in_memory(t_env *e, int val, int pos, t_proc *proc)
{
	int i;
	int j;
	unsigned char u;
	char mem_hexa[2];
	int color;

	i = -1;
	color = 0;
	while (++i < 4)
	{
		u = val >> (24 - (8 * i));
		e->mem[(pos + i) % MEM_SIZE] = u;
		if (have_opt('c', e->opt))
		{
			j = -1;
			e->col[(pos + i) % MEM_SIZE] = proc->champ_color;
			while (++j < 2)
			{
				mem_hexa[j] = BASE_HEXA[u % 16];
				u /= 16;
			}
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3, mem_hexa[1]);
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3 + 1, mem_hexa[0]);
			mvaddch((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3 + 2, ' ');
			mvchgat((pos + i) % MEM_SIZE / 64, ((pos + i) % MEM_SIZE % 64) *\
			3, 2, A_NORMAL, proc->champ_color, NULL);
		}
	}
}

void print_instruction(t_proc * proc, int nb_arg, char *inst, int store)
{
	int i;

	i = -1;
	ft_printf("P %4d | %s", proc->index, inst);
	while (++i < nb_arg)
	{
		if (((proc->inst.odc >> (6 - i * 2)) & IND_CODE) == IND_CODE)
			ft_printf(" %d", proc->inst.arg[i]);
		else if (((proc->inst.odc >> (6 - i * 2)) & DIR_CODE) == DIR_CODE)
			ft_printf(" %d", proc->inst.arg[i]);
		else if (((proc->inst.odc >> (6 - i * 2)) & REG_CODE) == REG_CODE)
			ft_printf(" r%d", proc->inst.arg[i]);
		else if (proc->inst.opc == 1)
			ft_printf(" %d", proc->inst.arg[i]);
	}
	ft_putchar('\n');
	if (store == 1)
		ft_putendl("store");
}

void print_adv(t_proc * proc, t_env *e, int bloque)
{
	int i;

	i = -1;
	if (proc->inst.opc == 9 && bloque)
		return ;
	ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", proc->inst.size, proc->pos,\
	(proc->pos + proc->inst.size) % MEM_SIZE);
	while (++i < proc->inst.size)
		ft_printf("%.2x ", e->mem[(proc->pos + i) % MEM_SIZE]);
	ft_putchar('\n');
}
