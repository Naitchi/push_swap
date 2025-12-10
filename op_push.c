/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:14 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 12:15:39 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

void	ft_op_push(t_list **lst_a, t_list **lst_b, char which_stack)
{
	t_list *ptr;
	long long temp_value;

	if ((which_stack == 'a' && !(*lst_b)) || (which_stack == 'b' && !(*lst_a)))
			return;

	if (which_stack == 'a')
	{
		temp_value = (*lst_b)->value;
		ptr = (*lst_b)->next;
		ft_lstdelone(*lst_b);
		**lst_b = *ptr;
		ft_lstadd_front(&lst_a, ft_lstnew(temp_value));
	}
	if (which_stack == 'b')
	{
		temp_value = (*lst_a)->value;
		ptr = (*lst_a)->next;
		ft_lstdelone(*lst_a);
		**lst_a = *ptr;
		ft_lstadd_front(&lst_b, ft_lstnew(temp_value));
	}
	ft_printf("%c%c", 'p', which_stack);
	return;
}