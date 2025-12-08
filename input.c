/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:15:35 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/08 20:30:01 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(int argc, char *argv[], t_data *data);
{
	int i;
	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;

	i = 2;
	if (is_strategy(argv[1]) == -1)
		i = 1;
	while (i < argc)
	{
		ft_atoi(argv[i], &data);
		i++;
	}
	return ;
}

int	is_strategy(char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "--"))
		return (-1);
	else if (!ft_strcmp(&str[2], "simple"))
		return (1);
	else if (!ft_strcmp(&str[2], "medium"))
		return (2);
	else if (!ft_strcmp(&str[2], "complex"))
		return (3);
	else if (!ft_strcmp(&str[2], "adaptive"))
		return (4);
	return (-1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	rslt;

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
}
