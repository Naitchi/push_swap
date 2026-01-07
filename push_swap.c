/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:53:39 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/07 13:44:03 by bclairot         ###   ########.fr       */
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
		ft_printf("Value: %d, Address: %p, prev: %p, next: %p\n",
			current_stack->value, (void *)current_stack, current_stack->prev,
			current_stack->next);
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
	printf("\n");
	// ft_bubble_sort(&data, &bench);
	// print_stack(data.a);
	// print_stack(data.b);
	radix(&data, &bench);
	printf("\n");
	show_bench(data, bench);
	return (0);
}
