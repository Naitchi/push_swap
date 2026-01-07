/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:14 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/07 11:47:07 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing(t_list **lst_src, t_list **lst_dst)
{
	t_list	*ptr;

	if (*lst_src)
	{
		ptr = *lst_src;
		if ((*lst_src)->next != NULL)
			(*lst_src)->next->prev = NULL;
		*lst_src = (*lst_src)->next;
		ptr->next = *lst_dst;
		if (ptr->next)
		{
			ptr->next->prev = ptr;
		}
		*lst_dst = ptr;
	}
	return ;
}

void	op_push(t_data *data, char which_stack, t_bench *bench)
{
	ft_printf("p%c\n", which_stack);
	if (which_stack == 'a')
		pushing(&data->b, &data->a);
	if (which_stack == 'b')
		pushing(&data->a, &data->b);
	if (which_stack == 'a')
		(*bench).pa++;
	if (which_stack == 'b')
		(*bench).pb++;
	return ;
}
