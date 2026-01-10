/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:34:32 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/09 21:34:32 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    adaptive(t_data *data, t_bench *bench)
{
    //int	size;
    //size = data->size_a; // TODO optimize for size and 3 or 5 elements arrays
    if(data.disorder_rate < 0.2)
		bubble_sort(&data, &bench);
    else if(data.disorder_rate >= 0.2 && data.disorder_rate < 0.5)
		bucket_ins_sort(&data, &bench);
    else 
		complex(&data, &bench);
}
