/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:51 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/08 16:54:09 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*return_next_max(t_list *lst)
{
	t_list	*res;

	res = NULL;
	while (lst)
	{
		if (!res && !lst->index)
			res = lst;
		if (res && res->value < lst->value && !lst->index)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

void	give_index(t_data *data)
{
	int		i;
	t_list	*elem;

	i = data->size_a;
	while (i > 0)
	{
		elem = return_next_max(data->a);
		elem->index = i;
		i--;
	}
	return ;
}
