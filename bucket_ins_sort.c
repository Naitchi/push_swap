/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_ins_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:26 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/07 14:31:05 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nb_buckets(t_data *data)
{
	int	i;

	i = 1;
	while (i * i <= data->size_a)
		i++;
	return (i - 1);
}

// check if rotate or rev_rot is more appropriate to fetch the element
int	value_present(int value, int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == values[i])
			return (1);
		i++;
	}
	return (0);
}
void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = 0;
		i++;
		s++;
	}
	return ;
}

int	*create_array(t_data *data, int nb_values)
{
	t_list	*ptr;
	int		*values;
	int		i;

	ptr = data->a;
	i = 0;
	values = malloc(sizeof(int) * nb_values);
	if (!values)
		return (NULL);
	ft_bzero(values, (nb_values * sizeof(int)));
	while (i < nb_values)
	{
		while (ptr != NULL)
		{
			if (ptr->value > values[i])
				if (value_present(ptr->value, values, i) == 0)
					values[i] = ptr->value;
			ptr = ptr->next;
		}
		ptr = data->a;
		i++;
	}
	return (values);
}

void	bucket_ins_sort(t_data *data, t_bench *bench)
{
	int	i;
	int	nb_buckets;
	int	nb_values;
	int	*temp_array;

	i = 0;
	nb_buckets = find_nb_buckets(data);
	nb_values = nb_buckets;
	while (is_stack_sorted(data) != 1)
	{
		while (nb_buckets > 1)
		{
			temp_array = create_array(data, nb_values);
			// if (temp_array == NULL)
			// 	exit;  to check
			while (i < nb_values)
			{
				if (value_present(data->a->value, temp_array, nb_values) == 1)
				{
					op_push(data, 'b', bench);
					i++;
				}
				else
					op_rotate(data, 'a', bench);
			}
			nb_buckets--;
			free(temp_array);
			i = 0;
		}
		while (data->a != NULL)
			op_push(data, 'b', bench);
		return ;
	}
}
