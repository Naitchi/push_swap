/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:35:27 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/12 16:02:55 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *lst)
{
	unsigned int	min;

	min = lst->index;
	while (lst)
	{
		if (lst->index < min)
			min = lst->index;
		lst = lst->next;
	}
	return (min);
}

int	find_max(t_list *lst)
{
	unsigned int	max;

	max = lst->index;
	while (lst)
	{
		if (lst->index > max)
			max = lst->index;
		lst = lst->next;
	}
	return (max);
}

int	*create_array(t_data *data, int nb_values)
{
	int	*array;
	int	min;
	int	i;

	i = 0;
	min = 0;
	array = malloc(sizeof(int) * nb_values);
	if (!array)
	{
		ft_lstclear(&data->a);
		ft_lstclear(&data->b);
		error_handler(0);
	}
	ft_bzero(array, (nb_values * sizeof(int)));
	min = find_min(data->a);
	while (i < nb_values)
	{
		array[i] = min + i;
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
