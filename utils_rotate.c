/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:14:44 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/13 10:03:56 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	nb_rot_needed_buck(t_list *lst, t_buckets *buck, int order)
{
	t_list	*ptr;
	int		nb;
	int		found;

	nb = 0;
	found = 0;
	if (order == 0)
		ptr = lst;
	else
		ptr = ft_lstlast(lst);
	while (ptr && found == 0)
	{
		if (is_value_present(ptr->index, buck->array, buck->values) == 0)
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
	return (nb + order);
}

int	rot_or_rev_buck(t_data *data, t_buckets *buck)
{
	int	next;
	int	prev;
	int	res;

	res = 0;
	next = nb_rot_needed_buck(data->a, buck, 0);
	prev = nb_rot_needed_buck(data->a, buck, 1);
	if (next > prev)
		res = 1;
	return (res);
}

int	nb_rot_needed(t_list *lst, unsigned int index, int order)
{
	t_list	*ptr;
	int		nb;
	int		found;

	nb = 0;
	found = 0;
	if (order == 0)
		ptr = lst;
	else
		ptr = ft_lstlast(lst);
	while (ptr && found == 0)
	{
		if (ptr->index != index)
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
	return (nb + order);
}

int	rot_or_rev(t_list *lst, unsigned int index)
{
	int	next;
	int	prev;
	int	res;

	res = 0;
	next = nb_rot_needed(lst, index, 0);
	prev = nb_rot_needed(lst, index, 1);
	if (next > prev)
		res = 1;
	return (res);
}
