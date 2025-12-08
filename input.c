/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:15:35 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/08 18:53:04 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list	init_list(int size)
{
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || (c == '-' || c == '+'))
		return (1);
	return (0);
}

int	is_strategy(char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "--"))
		return (-1);
	else if (!ft_strcmp(str, "simple"))
		return (1);
	else if (!ft_strcmp(str, "medium"))
		return (2);
	else if (!ft_strcmp(str, "complex"))
		return (3);
	else if (!ft_strcmp(str, "adaptive"))
		return (4);
	return (-1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}