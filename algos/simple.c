/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:01:24 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/13 12:11:12 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_mngmt(t_data *data, t_bench *bench, unsigned int max)
{
	while (data->b->index != max)
	{
		if (rot_or_rev(data->b, max) == 0)
			op_rotate(data, 'b', bench);
		else
			op_reverse_rotate(data, 'b', bench);
	}
	op_push(data, 'b', bench);
}

void	insert_to_b(t_data *data, t_bench *bench)
{
	unsigned int	min;
	unsigned int	max;

	op_push(data, 'b', bench);
	while (data->a)
	{
		min = find_min(data->b);
		max = find_max(data->b);
		if (data->a->index < min || data->a->index > max)
			max_mngmt(data, bench, max);
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
}

void	smallsorting(t_data *data, t_bench *bench)
{
	if (data->a->index == 1)
	{
		op_rotate(data, 'a', bench);
		op_swap(data, 'a', bench);
		op_reverse_rotate(data, 'a', bench);
	}
	else if (data->a->index == 2 && data->a->next->index == 1)
		op_swap(data, 'a', bench);
	else if (data->a->index == 2 && data->a->next->index == 3)
		op_reverse_rotate(data, 'a', bench);
	else if (data->a->index == 3 && data->a->next->index == 2)
	{
		op_swap(data, 'a', bench);
		op_reverse_rotate(data, 'a', bench);
	}
	else if (data->a->index == 3 && data->a->next->index == 1)
		op_rotate(data, 'a', bench);
}

void	simple(t_data *data, t_bench *bench)
{
	if (find_max(data->a) <= 3)
		smallsorting(data, bench);
	else
	{
		insert_to_b(data, bench);
		while (data->b->index != find_max(data->b))
		{
			if (rot_or_rev(data->b, find_max(data->b)) == 0)
				op_rotate(data, 'b', bench);
			else
				op_reverse_rotate(data, 'b', bench);
		}
		while (data->b)
			op_push(data, 'a', bench);
	}
	return ;
}
