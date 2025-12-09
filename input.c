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

void	init_list(int argc, char *argv[], t_data *data)
{
	int i;
	int j;
	char **split_rslt;
	long long nbr;

	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	nbr = 0;
	i = 2;
	if (is_strategy(argv[1]) == -1)
		i = 1;
	while (i < argc)
	{
		// TODO refactor this part in a diffrent function
		if(is_split_needed(argv[i]))
		{
			split_rslt = ft_split(argv[i]);
			j = 0;
			while (split_rslt[j])
			{
				nbr = ft_atoi(split_rslt[j]);
				list_check_double(data->a, nbr);
				ft_lstadd_back(&data->a, ft_lstnew(&nbr));
				data->size_a++;
			}
		}
		else 
		{
			nbr = ft_atoi(split_rslt[j]);
			list_check_double(data->a, nbr);
			ft_lstadd_back(&data->a, ft_lstnew(&nbr));
			data->size_a++;
		}
		i++;
	}
	return ;
}
