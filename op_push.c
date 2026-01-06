/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:14 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 11:14:08 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushing(t_list **lst_src, t_list **lst_dst)
{
	t_list	*ptr;

	if (*lst_src)
	{
		ptr = *lst_src;
		if ((*lst_src)->next != NULL)
			(*lst_src)->next->prev = NULL;
		*lst_src = (*lst_src)->next;
		if (!*lst_dst)
		{
			*lst_dst = ft_lstnew(ptr->value);
			return ;
		}
		else
		{
			ptr->next = *lst_dst;
			(*lst_dst)->prev = ptr;
			*lst_dst = ptr;
		}
	}
	return ;
}

void	ft_op_push(t_data *data, char which_stack)
{
	printf("p%c", which_stack);
	if (which_stack == 'a')
		ft_pushing(&data->b, &data->a);
	if (which_stack == 'b')
		ft_pushing(&data->a, &data->b);
	return ;
}
