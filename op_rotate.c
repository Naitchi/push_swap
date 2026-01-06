/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:06 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 14:55:24 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotating(t_list **lst)
{
	t_list	*ptr_first;
	t_list	*ptr_last;

	if ((*lst)->next != NULL)
	{
		ptr_first = *lst;
		*lst = (*lst)->next;
		ptr_first->next->prev = NULL;
		ptr_first->next = NULL;
		ptr_last = ft_lstlast(*lst);
		ptr_first->prev = ptr_last;
		ptr_last->next = ptr_first;
	}
	return ;
}

void	op_rotate(t_data *data, char which_stack, t_bench *bench)
{
	ft_printf("%c%c", 'r', which_stack);
	if (which_stack == 'a' || which_stack == 'r')
		rotating(&data->a);
	if (which_stack == 'b' || which_stack == 'r')
		rotating(&data->b);
	if (which_stack == 'a')
		(*bench).ra++;
	if (which_stack == 'b')
		(*bench).rb++;
	if (which_stack == 's')
		(*bench).rr++;
	return ;
}
