/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:06:15 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/06 19:27:55 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	is_something_to_push(t_list *a, int max_bit)
// {
//     t_list *elem;

//     elem = a;
// 	while (elem)
// 	{
// 		if (!((elem->value >> max_bit) & 1))
// 			return (1);
// 		elem = elem->next;
// 	}
// 	return (0);
// }

static void	push_everything_from_b_with_iteration_to_a(t_data *data, t_bench *bench)
{
	while (data->b)
		ft_op_push(data, 'a', bench);
}

static int get_size_stack(t_list *st)
{
    int i = 0;
    while (st->next)
    {
        st = st->next;
        i++;
    }
    return (i);
}

static int get_max_bit(t_list *lst, int gap)
{
    int res;
    int max_bit;

    max_bit = 0;
    res = lst->value;
    while (lst->next)
    {
        if (lst->next->value > res)
            res = lst->next->value;
        lst = lst->next;
    }
    if (lst->value > res)
        res = lst->value + gap;
    while ((res >> max_bit) != 0)
        max_bit++;
    return (max_bit);
}

// static int still_neg(t_list *lst)
// {
    
// }

static long long get_min_val(t_list *lst)
{
    int res;

    res = lst->value;
    while (lst->next)
    {
        if (lst->next->value < res)
            res = lst->next->value;
        lst = lst->next;
    }
    if (lst->value < res)
        res = lst->value;
    if (res < 0)
        res = res * (-1);
    return (res);
}

void	radix(t_data *data, t_bench *bench)
{
	int         max_bit;
    long long   gap;
    int         i;
    int         j;
    
    j = 0;
    gap = get_min_val(data->a);
    if (gap == 0)
        printf("\n\n\n ZEEEEEEEEEEEEEEEEbYYYY\n\n");
    max_bit = get_max_bit(data->a, gap);
    printf("\n\nmin: %lld\n", gap);    
	while (j < max_bit)
	{
        i = 0;
        int size = get_size_stack(data->a);
		while (i <= size)
		{
            if (!(((data->a->value + gap) >> j) & 1))
                ft_op_push(data, 'b', bench);
            else
                ft_op_rotate(data, 'a', bench);
            i++;
		}
        printf("\nbitcheck: %d stack B :", j);
        print_stack(data->b);
		push_everything_from_b_with_iteration_to_a(data, bench);
        printf("stack A :");
        print_stack(data->a);
		j++;
	}
    printf("\n\nFINALE\n\n");
    print_stack(data->a);
}