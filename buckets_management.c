/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:27 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/09 12:19:24 by cydupire         ###   ########lyon.fr   */
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

int	find_smallest(t_list *lst)
{
	unsigned int	smallest;

	smallest = lst->index;
	while (lst)
	{
		if (lst->index < smallest)
			smallest = lst->index;
		lst = lst->next;
	}
	return (smallest);
}

int	*create_array(t_data *data, int nb_values)
{
	int	*array;
	int	smallest;
	int	i;

	i = 0;
	smallest = 0;
	array = malloc(sizeof(int) * nb_values);
	if (!array)
		error_handler(0);
	ft_bzero(array, (nb_values * sizeof(int)));
	smallest = find_smallest(data->a);
	while (i < nb_values)
	{
		array[i] = smallest + i;
		i++;
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