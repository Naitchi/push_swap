/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/28 10:23:50 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(va_list list)
{
	int		i;
	char	*str;
	int		n;

	i = va_arg(list, int);
	str = ft_itoa(i);
	if (str == NULL)
		return (-1);
	n = ft_putstr_int(str);
	free (str);
	return (n);
}
