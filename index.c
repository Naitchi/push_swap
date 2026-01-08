/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:27:51 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/08 16:30:48 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*return_next_max(t_list *lst)
{
	t_list	*res;

	res = lst;
    while (res->index != 0)
	    res = res->next;
	while (lst->next)
	{
		printf("index %d\n", lst->next->index);
		if (res->value < lst->value && !lst->index)
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
		printf("node : %lld\n", elem->value);
		elem->index = i;
		print_stack(data->a);
		i--;
	}
	return ;
}
