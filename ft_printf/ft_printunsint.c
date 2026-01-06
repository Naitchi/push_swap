/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/28 10:26:32 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsint(va_list list)
{
	unsigned int	i;
	char			*str;
	int				n;

	i = va_arg(list, unsigned int);
	str = ft_unsitoa(i);
	if (str == NULL)
		return (-1);
	n = ft_putstr_int(str);
	free (str);
	return (n);
}
