/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 21:34:32 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/13 12:11:40 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	adaptive(t_data *data, t_bench *bench)
{
	if (data->disorder_rate < 0.2 || data->size_a <= 10)
		simple(data, bench);
	else if (data->disorder_rate >= 0.5 || data->size_a >= 500)
		complex(data, bench);
	else
		medium(data, bench);
}
