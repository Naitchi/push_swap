/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:53:39 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 12:11:23 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*current_stack;

	current_stack = stack;
	if (!current_stack)
	{
		printf("Nothing in the stack.\n\n");
		return ;
	}
	printf("Stack contents:\n\n");
	while (current_stack)
	{
		printf("Value: %lld, Address: %p, prev: %p, next: %p\n",
			current_stack->value, (void *)current_stack, current_stack->prev,
			current_stack->next);
		current_stack = current_stack->next;
		if (current_stack)
			printf("-----------------------------------------------------\n");
		else
			printf("\n");
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_bench bench;

	parsing(argc, argv);
	//printf("Parsing done\nNo errors\n\n");
	init_list(argc, argv, &data, &bench);
	print_stack(data.a);
	print_stack(data.b);
	printf("\n");
	ft_bubble_sort(&data);
	print_stack(data.a);
	print_stack(data.b);
	printf("\n");
	

	show_bench(data, bench);
	return (0);
}
