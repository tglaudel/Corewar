/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:27:37 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/28 13:34:06 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *start;

	new = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!new)
		{
			new = tmp;
			start = new;
			new->next = NULL;
		}
		else
		{
			new->next = tmp;
			tmp->next = NULL;
			new = new->next;
		}
		lst = lst->next;
	}
	return (start);
}
