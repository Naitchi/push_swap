/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:09 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 16:26:06 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

void	ft_op_swap(t_list **lst_a, t_list **lst_b, char which_stack)
{
	ft_printf("s%c", which_stack);
	if (which_stack == 'a' || which_stack == 's')
	{
		if (*lst_a && (*lst_a)->next != NULL)
			ft_swapping(lst_a);
	}
	if (which_stack == 'b' || which_stack == 's')
	{
		if (*lst_b && (*lst_b)->next != NULL)
			ft_swapping(lst_b);
	}
	return;
}

void	ft_swapping(t_list **lst)
{
	long long	temp_value;

	temp_value = (*lst)->value;
	(*lst)->value = (*lst)->next->value;
	(*lst)->next->value = temp_value;
	return ;
}
