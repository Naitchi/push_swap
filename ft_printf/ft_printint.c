/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/10 12:41:31 by bclairot         ###   ########.fr       */
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
	free(str);
	return (n);
}
