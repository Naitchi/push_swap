/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:53:39 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/12 15:13:46 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_bench	bench;

	parsing(argc, argv);
	init_list(argc, argv, &data, &bench);
	if (!is_stack_sorted(&data))
	{
		if (data.strategy == 1)
			simple(&data, &bench);
		else if (data.strategy == 2)
			medium(&data, &bench);
		else if (data.strategy == 3)
			complex(&data, &bench);
		else
			adaptive(&data, &bench);
	}
	show_bench(data, bench);
	ft_lstclear(&data.a);
	return (0);
}
