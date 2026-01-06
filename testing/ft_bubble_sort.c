/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:01:24 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/06 11:15:53 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_data *data)
{
	t_list	*ptr;

	ptr = data->a;
	while (ft_is_stack_sorted(data) != 1)
	{
		if (ptr->value > ptr->next->value)
		{
			ft_op_swap(data, 'a');
			ft_op_rotate(data, 'a');
			ptr = data->a;
		}
		else
		{
			ft_op_rotate(data, 'a');
			ptr = data->a;
		}
	}
	return ;
}
