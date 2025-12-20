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


void	list_init_element(t_list *lst, const char *str)
{
	long long nbr;

	nbr = 0;
	nbr = ft_atoi(str);

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

void init_stack_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	data->strategy = 0;
	data->bench = 0;
	return ;
}

void	init_list(int argc, char *argv[], t_data *data)
{
	int i;
	int j;
	char **split_rslt;

	init_stack_data(data);
	i = init_flags(argc, argv, data) + 1;
	while (i < argc)
	{
		if(is_split_needed(argv[i]))
		{
			split_rslt = ft_split(argv[i]);
			j = 0;
			while (split_rslt[j])
			{
				list_init_element(data->a, split_rslt[j]);
				j++;
			}
		}
		else 
			list_init_element(data->a, argv[i]);
		i++;
	}
}
