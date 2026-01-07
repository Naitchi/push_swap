/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:40:49 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/07 14:42:18 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// maybe add atoi, strncmp here?

void	ft_bzero(void *s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = 0;
		i++;
		s++;
	}
	return ;
}