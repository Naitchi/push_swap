/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:53:39 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/09 11:32:43 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*current_stack;

	current_stack = stack;
	if (!current_stack)
	{
		ft_printf("Nothing in the stack.\n\n");
		return ;
	}
	ft_printf("Stack contents:\n\n");
	while (current_stack)
	{
		ft_printf("Value: %d,Index: %d, Address: %p, prev: %p, next: %p\n",
			current_stack->value, current_stack->index, (void *)current_stack,
			current_stack->prev, current_stack->next);
		current_stack = current_stack->next;
		if (current_stack)
			ft_printf("%s",
				"-----------------------------------------------------\n");
		else
			ft_printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_bench	bench;

	parsing(argc, argv);
	// printf("Parsing done\nNo errors\n\n");
	init_list(argc, argv, &data, &bench);
	print_stack(data.a);
	print_stack(data.b);
	ft_printf("\n");
	// bubble_sort(&data, &bench);
	bucket_ins_sort(&data, &bench);
	// radix(&data, &bench);
	print_stack(data.a);
	print_stack(data.b);
	ft_printf("\n");
	// show_bench(data, bench);
	ft_lstclear(&data.b);
	return (0);
}
