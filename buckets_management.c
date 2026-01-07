/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:27 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/07 17:55:13 by cydupire         ###   ########lyon.fr   */
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

int	is_value_present(int value, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (value == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	*create_array(t_data *data, int nb_values)
{
	t_list	*ptr;
	int		*array;
	int		i;

	ptr = data->a;
	i = 0;
	array = malloc(sizeof(int) * nb_values);
	if (!array)
		error_handler(0);
	ft_bzero(array, (nb_values * sizeof(int)));
	while (i < nb_values)
	{
		while (ptr != NULL)
		{
			if (ptr->value > array[i])
				// error, the stak needs to be in the reversed order.
				if (is_value_present(ptr->value, array, i) == 0)
					array[i] = ptr->value;
			ptr = ptr->next;
		}
		ptr = data->a;
		i++;
	}
	return (array);
}
void	find_nb_values(t_data *data, t_buckets *buck)
{
	if (data->size_a % buck->buckets != 0)
		buck->values = buck->buckets + 1;
	else
		buck->values = buck->buckets;
}

void	update_buckets(t_data *data, t_buckets *buck)
{
	find_nb_values(data, buck);
	buck->array = create_array(data, buck->values);
}