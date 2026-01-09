/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_ins_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:26 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/09 13:41:42 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing_to_b(t_data *data, t_bench *bench, t_buckets *buck)
{
	int	j;
	int	order;

	j = 0;
	order = rotate_or_reverse(data, buck);
	while (j < buck->values)
	{
		if (is_value_present(data->a->index, buck->array, buck->values) == 1)
		{
			op_push(data, 'b', bench);
			j++;
		}
		else if (order == 0)
			op_rotate(data, 'a', bench);
		else
			op_reverse_rotate(data, 'a', bench);
	}
}

void	bucket_ins_sort(t_data *data, t_bench *bench)
{
	int			i;
	t_buckets	buck;

	i = 0;
	buck.buckets = find_nb_buckets(data);
	buck.mod = data->size_a % buck.buckets;
	// while (is_stack_sorted(data) != 1)
	// {
	while (i++ < buck.buckets)
	{
		update_buckets(data, &buck);
		pushing_to_b(data, bench, &buck);
		free(buck.array);
	}
	while (data->a != NULL)
		op_push(data, 'b', bench);
	return ;
	// }
}
