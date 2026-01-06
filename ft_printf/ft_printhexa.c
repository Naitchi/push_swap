/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/28 10:36:07 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_hexa_multi(int len)
{
	unsigned int	multi;

	multi = 1;
	while (len > 1)
	{
		multi = multi * 16;
		len--;
	}
	return (multi);
}

static unsigned int	ft_hexa_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while ((n / 16) != 0)
	{
		n = n / 16;
		len++;
	}
	len++;
	return (len);
}

static char	*ft_convhexa(unsigned int n, char c)
{
	char			*hexa;
	unsigned int	len;
	char			*res;
	unsigned int	i;

	if (c == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	len = ft_hexa_len(n);
	res = malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = hexa[n / ft_hexa_multi(len - i)];
		n = n % ft_hexa_multi(len - i);
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_printhexa(va_list list, char c)
{
	unsigned int	u;
	char			*str;
	int				n;

	u = va_arg(list, unsigned int);
	str = ft_convhexa(u, c);
	if (str == NULL)
		return (-1);
	n = ft_putstr_int(str);
	free (str);
	return (n);
}
