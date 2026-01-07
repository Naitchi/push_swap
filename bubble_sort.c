/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:01:24 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/07 11:49:52 by cydupire         ###   ########lyon.fr   */
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
			op_rotate(data, 'a', bench);
			i++;
		}
		i = 0;
		op_rotate(data, 'a', bench);
	}
	return ;
}
