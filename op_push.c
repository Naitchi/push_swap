/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:30:14 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 16:25:47 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

void	ft_op_push(t_list **lst_a, t_list **lst_b, char which_stack)
{
	ft_printf("p%c", which_stack);
	if (which_stack == 'a')
	{
		if (*lst_b)
			ft_pushing(lst_b, lst_a);
	}
	if (which_stack == 'b')
	{
		if (*lst_a)
			ft_pushing(lst_a, lst_b);
	}
	return;
}

void	ft_pushing(t_list **lst_src, t_list **lst_dst)
{

	(*lst_src)->next->prev = NULL;
	(*lst_src)->next = lst_dst;
	(*lst_dst)->prev = lst_src;
	*lst_dst = *lst_src;
	return ;
}
