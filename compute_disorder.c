/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:52:59 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/21 15:47:22 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list *stack)
{
	float	mistakes;
	float	total_pairs;
	t_list	*first;
	t_list	*second;

	total_pairs = 0;
	mistakes = 0;
	first = stack;
	while (first)
	{
		second = first->next;
		while (second)
		{
			total_pairs++;
			if (first->value > second->value)
				mistakes++;
			second = second->next;
		}
		first = first->next;
	}
	return (mistakes / total_pairs);
}
