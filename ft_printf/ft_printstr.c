/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/26 10:50:43 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_int(char *s)
{
	int	i;
	int	n;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		n = write(1, &s[i], 1);
		if (n == -1)
			return (n);
		i++;
	}
	return (i);
}

int	ft_printstr(va_list list)
{
	char	*str;
	int		n;

	str = va_arg(list, char *);
	n = ft_putstr_int(str);
	return (n);
}
