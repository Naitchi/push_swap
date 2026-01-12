/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:01:24 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/12 19:50:15 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simple(t_data *data, t_bench *bench)
{
	unsigned int	min;
	unsigned int	max;

	op_push(data, 'b', bench);
	while (data->a)
	{
		min = find_min(data->b);
		max = find_max(data->b);
		if (data->a->index < min || data->a->index > max)
		{
			while (data->b->index != max)
				op_reverse_rotate(data, 'b', bench);
			op_push(data, 'b', bench);
		}
		else if (data->a->index < data->b->index
			&& data->a->index > ft_lstlast(data->b)->index)
			op_reverse_rotate(data, 'b', bench);
		else if (data->a->index < data->b->index)
			op_rotate(data, 'b', bench);
		else if (data->a->index > data->b->index
			&& data->a->index > ft_lstlast(data->b)->index)
			op_reverse_rotate(data, 'b', bench);
		else
			op_push(data, 'b', bench);
	}
	while (data->b->index != find_max(data->b))
		op_rotate(data, 'b', bench);
	while (data->b)
		op_push(data, 'a', bench);
	return ;
}
