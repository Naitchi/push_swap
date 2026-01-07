/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_ins_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:26 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/07 17:48:58 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if rotate or rev_rot is more appropriate to fetch the element

void	bucket_ins_sort(t_data *data, t_bench *bench)
{
	int			i;
	t_buckets	buck;

	i = 0;
	buck.buckets = find_nb_buckets(data);
	while (is_stack_sorted(data) != 1)
	{
		while (buck.buckets > 1)
		{
			update_buckets(data, &buck);
			while (i < buck.values)
			{
				if (is_value_present(data->a->value, buck.array,
						buck.values) == 1)
				{
					op_push(data, 'b', bench);
					i++;
				}
				else
					op_rotate(data, 'a', bench);
			}
			buck.buckets--;
			free(buck.array);
			i = 0;
		}
		while (data->a != NULL)
			op_push(data, 'b', bench);
		return ;
	}
}
