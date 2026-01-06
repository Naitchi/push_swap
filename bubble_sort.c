/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:01:24 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/06 14:09:17 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_data *data, t_bench *bench)
{
	t_list		*ptr;
	long long	i;
	long long	size;

	ptr = data->a;
	i = 0;
	size = data->size_a;
	while (is_stack_sorted(data) != 1)
	{
		while (i < size - 1)
		{
			if (ptr->value > ptr->next->value)
				op_swap(data, 'a', bench);
			op_rotate(data, 'a', bench);
			ptr = data->a;
			i++;
		}
		i = 0;
		op_rotate(data, 'a', bench);
		ptr = data->a;
	}
	return ;
}
