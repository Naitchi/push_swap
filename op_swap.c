/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:09 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 11:58:44 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

void	ft_op_swap(t_list **lst_a, t_list **lst_b, char which_stack)
{
	t_list *ptr;
	long long temp_value;

	if (!(*lst_a) || (*lst_a)->next == NULL
		|| !(*lst_b) || (*lst_b)->next == NULL)
			return;

	if (which_stack == 'a' || which_stack == 's')
	{
		temp_value = (*lst_a)->value;
		(*lst_a)->value = (*lst_a)->next->value;
		ptr = *lst_a;
		ptr = (*lst_a)->next;
		ptr->value = temp_value;
	}
	if (which_stack == 'b' || which_stack == 's')
	{
		temp_value = (*lst_b)->value;
		(*lst_b)->value = (*lst_b)->next->value;
		ptr = *lst_b;
		ptr = (*lst_b)->next;
		ptr->value = temp_value;
	}
	ft_printf("%c%c", 's', which_stack);
	return;
}
