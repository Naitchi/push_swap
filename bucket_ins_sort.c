/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_ins_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:26 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/12 10:55:11 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_to_a(t_data *data, t_bench *bench)
{
	unsigned int	min;
	unsigned int	max;

	op_push(data, 'a', bench);
	while (data->b)
	{
		min = find_min(data->a);
		max = find_max(data->a);
		if (data->b->index < min || data->b->index > max)
		{
			while (data->a->index != min)
			{
				if (rot_or_rev(data, min) == 0)
					op_rotate(data, 'a', bench);
				else
					op_reverse_rotate(data, 'a', bench);
			}
			op_push(data, 'a', bench);
		}
		else if (data->b->index > data->a->index)
			op_rotate(data, 'a', bench);
		else if (data->b->index > ft_lstlast(data->a)->index
			&& data->b->index > data->a->index)
			op_reverse_rotate(data, 'a', bench);
		else if (data->b->index < ft_lstlast(data->a)->index
			&& data->b->index < data->a->index)
			op_reverse_rotate(data, 'a', bench);
		else
			op_push(data, 'a', bench);
	}
}

void	push_to_b(t_data *data, t_bench *bench, t_buckets *buck)
{
	int	j;

	j = 0;
	while (j < buck->values)
	{
		if (is_value_present(data->a->index, buck->array, buck->values) == 1)
		{
			op_push(data, 'b', bench);
			j++;
		}
		else if (rot_or_rev_buck(data, buck) == 0)
			op_rotate(data, 'a', bench);
		else
			op_reverse_rotate(data, 'a', bench);
	}
}

int	find_nb_buckets(t_data *data)
{
	int	i;

	i = 1;
	while (i * i <= data->size_a)
		i++;
	return (i - 1);
}

void	bucket_ins_sort(t_data *data, t_bench *bench)
{
	int			i;
	t_buckets	buck;

	i = 0;
	buck.buckets = find_nb_buckets(data);
	buck.mod = data->size_a % buck.buckets;
	while (i++ < buck.buckets)
	{
		update_buckets(data, &buck);
		push_to_b(data, bench, &buck);
		free(buck.array);
	}
	while (data->b)
	{
		insert_to_a(data, bench);
	}
	while (is_stack_sorted(data) != 1)
	{
		op_reverse_rotate(data, 'a', bench);
	}
	return ;
}
