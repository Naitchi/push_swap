/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:01:33 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/08 18:57:30 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "list_utils.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	s_list			*a;
	s_list			*b;
	int				size_a;
	int				size_b;
}					t_data;

typedef struct t_list
{
	long long		value;
	struct s_list	*next;
}					s_list;

#endif