/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_ins_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:26 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/09 10:50:04 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if rotate or rev_rot is more appropriate to fetch the element

void	pushing_into_bucket(t_data *data, t_bench *bench, t_buckets *buck)
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
		else
			rotate_or_reverse(data, bench, buck);
	}
}

int	nb_rot_needed(t_list *lst, t_buckets *buck, int order)
{
	t_list	*ptr;
	int		nb;
	int		found;

	if (order == 0)
		ptr = lst;
	else
		ptr = ft_lstlast(lst);
	while (ptr && found == 0)
	{
		if (!is_value_present(lst->index, buck->array, buck->values) == 0)
		{
			if (order == 0)
				ptr = ptr->next;
			else
				ptr = ptr->prev;
			nb++;
		}
		else
			found = 1;
	}
	return (nb);
}

void	rotate_or_reverse(t_data *data, t_bench *bench, t_buckets *buck)
{
	int	next;
	int	prev;

	next = nb_rot_needed(data->a, buck, 0);
	prev = nb_rot_needed(data->a, buck, 1);
	if (next < prev)
		op_rotate(data, 'a', bench);
	else
		op_reverse_rotate(data, 'a', bench);
}

void	bucket_ins_sort(t_data *data, t_bench *bench)
{
	int			i;
	t_buckets	buck;

	i = 0;
	buck.buckets = find_nb_buckets(data);
	buck.mod = data->size_a % buck.buckets;
	while (is_stack_sorted(data) != 1)
	{
		while (i++ < buck.buckets)
		{
			update_buckets(data, &buck);
			pushing_into_bucket(data, bench, &buck);
			free(buck.array);
		}
		while (data->a != NULL)
			op_push(data, 'b', bench);
		return ;
	}
}
