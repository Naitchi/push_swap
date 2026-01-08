/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:27 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/08 16:31:18 by cydupire         ###   ########lyon.fr   */
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
	t_list	*ptr_value;
	t_list	*ptr_runner;
	int		*array;
	int		smallest;
	int		i;

	ptr_value = data->a;
	ptr_runner = data->a->next;
	i = 0;
	smallest = 0;
	array = malloc(sizeof(int) * nb_values);
	if (!array)
		error_handler(0);
	ft_bzero(array, (nb_values * sizeof(int)));
	while (i < nb_values)
	{
		// if (is_value_present(ptr_value->value, array, nb_values) == 0)
		// {
		// 	smallest = ptr_value->value;
		// 	while (ptr_runner != NULL)
		// 	{
		// 		if (smallest > ptr_runner->value)
		// 			smallest = 0;
		// 		ptr_runner = ptr_runner->next;
		// 	}
		// }
		// if (smallest > 0)
		// {
		// 	array[i] = smallest;
		// 	i++;
		// }
		// ptr_value = ptr_value->next;
	}
	return (array);
}

void	find_nb_values(t_data *data, t_buckets *buck)
{
	if (buck->mod != 0)
	{
		buck->values = (data->size_a / buck->buckets) + 1;
		buck->mod--;
	}
	else
		buck->values = data->size_a / buck->buckets;
}

void	update_buckets(t_data *data, t_buckets *buck)
{
	find_nb_values(data, buck);
	buck->array = create_array(data, buck->values);
}