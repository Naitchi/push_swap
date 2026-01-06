/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:15:35 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 12:06:26 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i = 0;

	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	list_init_element(t_data *data, const char *str)
{
	long long	nbr;
	t_list *lst;

	nbr = 0;
	nbr = ft_atoi(str);
	lst = data->a;
	while (lst)
	{
		if (lst->value == nbr)
			error_handler(0);
		lst = lst->next;
	}
	ft_lstadd_back(&data->a, ft_lstnew(nbr));
	data->size_a++;
	return ;
}

void	init_stack_data(t_data *data, t_bench *bench)
{
	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->strategy = 0;
	data->disorder_rate = 0;
	data->bench = 0;
	bench->sa = 0;	
	bench->sb = 0;
	bench->ss = 0;	
	bench->pa = 0;	
	bench->pb = 0;	
	bench->ra = 0;
	bench->rb = 0;	
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;	
	bench->rrr = 0;
	return ;
}

void	init_list(int argc, char *argv[], t_data *data, t_bench *bench)
{
	int		i;
	int		j;
	char	**split_rslt;

	init_stack_data(data, bench);
	i = init_flags(argc, argv, data) + 1;
	while (i < argc)
	{
		if (is_split_needed(argv[i]))
		{
			split_rslt = ft_split(argv[i]);
			j = 0;
			while (split_rslt[j])
			{
				list_init_element(data, split_rslt[j]);
				j++;
			}
		}
		else
			list_init_element(data, argv[i]);
		i++;
	}
	if (data->strategy == 0)
		data->strategy = 4;
	data->disorder_rate = compute_disorder(data->a);
}
