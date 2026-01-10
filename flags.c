/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:11:03 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/10 12:42:21 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_flag(char *str)
{
	if (!str || ft_strncmp(str, "--", 2) != 0)
		return (-1);
	if (ft_strncmp(str + 2, "simple", 7) == 0)
		return (1);
	if (ft_strncmp(str + 2, "medium", 7) == 0)
		return (2);
	if (ft_strncmp(str + 2, "complex", 8) == 0)
		return (3);
	if (ft_strncmp(str + 2, "adaptive", 9) == 0)
		return (4);
	if (ft_strncmp(str + 2, "bench", 6) == 0)
		return (5);
	return (-1);
}

// Init flags in data and return the number of flags found
int	init_flags(int argc, char *argv[], t_data *data)
{
	int	nbr_flags;
	int	flag_type;

	if (argc < 3)
		return (0);
	nbr_flags = 0;
	flag_type = 0;
	while (nbr_flags + 1 < argc && flag_type != -1)
	{
		flag_type = is_a_flag(argv[nbr_flags + 1]);
		if (flag_type > 0 && flag_type < 5 && !data->strategy)
			data->strategy = flag_type;
		else if (flag_type == 5 && !data->bench)
			data->bench = flag_type;
		else if (flag_type > 0 && flag_type < 5 && data->strategy)
			error_handler(0);
		else if (flag_type == 5 && data->bench)
			error_handler(0);
		else
			return (nbr_flags);
		nbr_flags++;
	}
	if (nbr_flags + 1 == argc)
		exit(1);
	return (nbr_flags);
}
