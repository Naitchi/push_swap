/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:06 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 16:28:56 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

void	ft_op_rotate(t_list **lst_a, t_list **lst_b, char which_stack)
{
	ft_printf("%c%c", 'r', which_stack);
	if (which_stack == 'a' || which_stack == 'r')
	{
		if ((*lst_a)->next != NULL)
			ft_rotating(lst_a);
	}
	if (which_stack == 'b' || which_stack == 'r')
	{
		if ((*lst_b)->next != NULL)
			ft_rotating(lst_b);
	}
	return;
}

void	ft_rotating(t_list **lst)
{
	t_list	*ptr;

	(*lst)->next->prev = NULL;
	(*lst)->next = NULL;
	ptr = ft_lstlast(*lst);
	(*lst)->prev = ptr;
	ptr->next = *lst;
	*lst = ft_lstfirst(*lst);
}
