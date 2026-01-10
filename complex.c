/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:06:15 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/10 11:48:18 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_everything_from_b_to_a(t_data *data, t_bench *bench)
{
	while (data->b)
		op_push(data, 'a', bench);
}

static int	get_size_stack(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

static int	get_max_bit(t_data *data)
{
	int	max_bit;

	max_bit = 0;
	while ((data->size_a >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

void	complex(t_data *data, t_bench *bench)
{
	int max_bit;
	int i;
	int j;

	j = 0;
	max_bit = get_max_bit(data);
	while (j < max_bit)
	{
		i = 0;
		int size = get_size_stack(data->a);
		while (i <= size)
		{
			if (!(((data->a->index) >> j) & 1))
				op_push(data, 'b', bench);
			else
				op_rotate(data, 'a', bench);
			if (data->a && is_stack_sorted(data))
				break ;
			i++;
		}
		push_everything_from_b_to_a(data, bench);
		j++;
	}
}
