/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:04:05 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/28 10:42:06 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checktype(va_list list, const char c)
{
	if (c == 'c')
		return (ft_printchar(list));
	if (c == 's')
		return (ft_printstr(list));
	if (c == 'p')
		return (ft_printptr(list));
	if (c == 'd' || c == 'i')
		return (ft_printint(list));
	if (c == 'u')
		return (ft_printunsint(list));
	if (c == 'x' || c == 'X')
		return (ft_printhexa(list, c));
	else
		return (write(1, "%", 1));
}

static int	ft_printall(char *str, va_list list)
{
	size_t	i;
	int		r;
	int		t;

	i = 0;
	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			t = write(1, &str[i], 1);
			i++;
			r += 1;
		}
		else
		{
			t = ft_checktype(list, str[i + 1]);
			i += 2;
			r += t;
		}
		if (t == -1)
			return (-1);
	}
	return (r);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		r;

	r = 0;
	if (str == NULL)
		return (-1);
	va_start(list, str);
	r = ft_printall((char *)str, list);
	va_end(list);
	return (r);
}
