/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:34:32 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/12 15:02:02 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive(t_data *data, t_bench *bench)
{
	// int	size;
	// size = data->size_a; // TODO optimize for size and 3 or 5 elements arrays
	if (data->disorder_rate < 0.2 && data->size_a <= 10)
		simple(data, bench);
	else if (data->disorder_rate >= 0.5 || data->size_a >= 500)
		complex(data, bench);
	else
		medium(data, bench);
}
