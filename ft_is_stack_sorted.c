/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_stack_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:02:05 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/06 09:21:37 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_stack_sorted(t_data *data)
{
	t_list		*ptr;

	ptr = data->a;
	while (ptr->next != NULL)
	{
		if (ptr->value < ptr->next->value)
			ptr = ptr->next;
		else
			return (0);
	}
	if (data->b != NULL)
		return (0);
	else
		return (1);
}
