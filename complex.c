/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:06:15 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/07 18:48:31 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_something_to_push(t_list *lst, int index, int gap)
{
	while (lst->next)
	{
		if (!(((lst->value + gap) >> index) & 1))
			return (0);
		lst = lst->next;
	}
	if (!(((lst->value + gap) >> index) & 1))
	{
		return (0);
	}
	return (1);
}

static void	push_everything_from_list_b_to_list_a_using_iteration(t_data *data,
		t_bench *bench)
{
	while (data->b)
		op_push(data, 'a', bench);
}

static int	get_size_stack(t_list *st)
{
	int	i;

	i = 0;
	while (st->next)
	{
		st = st->next;
		i++;
	}
	return (i);
}

static int	get_max_bit(t_list *lst, int gap)
{
	int	res;
	int	max_bit;

	max_bit = 0;
	res = lst->value;
	while (lst->next)
	{
		if (lst->next->value > res)
			res = lst->next->value;
		lst = lst->next;
	}
	if (lst->value > res)
		res = lst->value + gap;
	while ((res >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

static long long	get_min_val(t_list *lst)
{
	int	res;

	res = lst->value;
	while (lst->next)
	{
		if (lst->next->value < res)
			res = lst->next->value;
		lst = lst->next;
	}
	if (lst->value < res)
		res = lst->value;
	if (res < 0)
		res = res * (-1);
	return (res);
}

void	radix(t_data *data, t_bench *bench)
{
	int max_bit;
	long long gap;
	int i;
	int j;
	// long long head_of

	j = 0;
	gap = get_min_val(data->a);
	max_bit = get_max_bit(data->a, gap);
	while (j < max_bit)
	{
		i = 0;
		int size = get_size_stack(data->a);
		if (is_something_to_push(data->a, j, gap))
		{
			continue ;
		}
		while (i <= size)
		{
			if (!(((data->a->value + gap) >> j) & 1))
				op_push(data, 'b', bench);
			else
				op_rotate(data, 'a', bench);
			if (is_stack_sorted(data))
				break ;

			i++;
		}
		push_everything_from_list_b_to_list_a_using_iteration(data, bench);
		j++;
	}
}