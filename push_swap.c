/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:53:39 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/10 11:48:27 by bclairot         ###   ########.fr       */
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
	init_list(argc, argv, &data, &bench);
	if (data.strategy == 1)	
		bubble_sort(&data, &bench);
	else if (data.strategy == 2)
		bucket_ins_sort(&data, &bench);
	else if (data.strategy == 3)
		complex(&data, &bench);
	else (data.strategy == 4)
		adaptive(&data, &bench);

	show_bench(data, bench);
	return (0);
}
