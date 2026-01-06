/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:09 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 14:00:23 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swapping(t_list **lst)
{
	long long	temp_value;

	if (*lst && (*lst)->next != NULL)
	{
		temp_value = (*lst)->value;
		(*lst)->value = (*lst)->next->value;
		(*lst)->next->value = temp_value;
	}
	return ;
}

void	ft_op_swap(t_data *data, char which_stack, t_bench *bench)
{
	printf("s%c", which_stack);
	if (which_stack == 'a' || which_stack == 's')
		ft_swapping(&data->a);
	if (which_stack == 'b' || which_stack == 's')
		ft_swapping(&data->b);
	if (which_stack == 'a')
		(*bench).sa++;
	if (which_stack == 'b')
		(*bench).sb++;
	if (which_stack == 's')
		(*bench).ss++;
	return ;
}
