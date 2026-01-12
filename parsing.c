/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:32:29 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/12 14:06:53 by cydupire         ###   ########lyon.fr   */
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

void	check_int_range(char *s)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		sign = 1;
		if (s[i] == '+' || s[i] == '-')
		{
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		num = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
			if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
				error_handler(0);
			i++;
		}
	}
}

void	parsing(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (is_a_flag(argv[i]) != -1)
		i++;
	j = 0;
	if (argc <= 1)
		exit(1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-'
				&& argv[i][j] != '+' && !ft_isspace(argv[i][j]))
				error_handler(0);
			check_int_range(argv[i]);
			j++;
		}
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rslt;

	i = 0;
	sign = 1;
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
		if (sign == 1 && (rslt > (INT_MAX - (str[i] - '0')) / 10))
			return (INT_MAX);
		if (sign == -1 && (rslt > (-(INT_MIN + (str[i] - '0'))) / 10))
			return (INT_MIN);
		rslt = rslt * 10 + (str[i] - '0');
		i++;
	}
	return (rslt * sign);
}
