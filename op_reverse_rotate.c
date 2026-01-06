/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:03 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 14:09:30 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotating(t_list **lst)
{
	t_list	*ptr;

	ptr = ft_lstlast(*lst);
	if (ptr->prev != NULL)
	{
		ptr = ft_lstlast(*lst);
		ptr->prev->next = NULL;
		ptr->prev = NULL;
		ptr->next = *lst;
		(*lst)->prev = ptr;
		*lst = ptr;
	}
	return ;
}

void	op_reverse_rotate(t_data *data, char which_stack, t_bench *bench)
{
	printf("%s%c", "rr", which_stack);
	if (which_stack == 'a' || which_stack == 'r')
		reverse_rotating(&data->a);
	if (which_stack == 'b' || which_stack == 'r')
		reverse_rotating(&data->b);
	if (which_stack == 'a')
		(*bench).rra++;
	if (which_stack == 'b')
		(*bench).rrb++;
	if (which_stack == 's')
		(*bench).rrr++;
	return ;
}
