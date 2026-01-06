/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:32:29 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 11:30:49 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_split_needed(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	parsing(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (is_a_flags(argv[i]) != -1)
		i++;
	j = 0;
	if (argc <= 1)
		error_handler(0);
	while (i < argc)
	{
		// printf("Parsing arg %d: %s\n", i, argv[i]);
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-'
				&& argv[i][j] != '+' && !ft_isspace(argv[i][j]))
				error_handler(0);
			j++;
		}
		i++;
	}
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	rslt;

	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (-9223372036854775807);
	sign = 1;
	i = 0;
	rslt = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt *= 10;
		rslt += (str[i] - '0');
		i++;
	}
	return (rslt * sign);
}
