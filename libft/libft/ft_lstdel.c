/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglaudel <tglaudel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:23:55 by tglaudel          #+#    #+#             */
/*   Updated: 2015/11/28 13:10:41 by tglaudel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;
	t_list *nextlst;

	temp = *alst;
	while (temp)
	{
		nextlst = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = nextlst;
	}
	*alst = NULL;
}
