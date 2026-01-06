/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/28 10:20:53 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list list)
{
	int				i;
	unsigned char	c;

	i = va_arg(list, int);
	c = i;
	return (write(1, &c, 1));
}
