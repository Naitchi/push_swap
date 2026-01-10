/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:18:49 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/10 12:44:48 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO modifier les parametres pour free aussi ?
void	error_handler(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "Error\n";
	while (str[i])
		i++;
	write(2, str, i);
	exit(1);
}
