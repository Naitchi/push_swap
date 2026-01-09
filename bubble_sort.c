/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:01:24 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/07 16:39:43 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_data *data, t_bench *bench)
{
	int	i;

	i = 0;
	while (is_stack_sorted(data) != 1)
	{
		while (i < data->size_a - 1)
		{
			if (data->a->value > data->a->next->value)
				op_swap(data, 'a', bench);
			if (is_stack_sorted(data) == 1)
				return ;
			op_rotate(data, 'a', bench);
			i++;
		}
		i = 0;
		op_rotate(data, 'a', bench);
	}
	return ;
}
