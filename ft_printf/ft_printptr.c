/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:17:20 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/10 12:41:38 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hexalong_multi(size_t len)
{
	size_t	multi;

	multi = 1;
	while (len > 1)
	{
		multi = multi * 16;
		len--;
	}
	return (multi);
}

static size_t	ft_hexalong_len(size_t n)
{
	size_t	len;

	len = 0;
	while ((n / 16) != 0)
	{
		n = n / 16;
		len++;
	}
	len++;
	return (len);
}

void	ft_convlonghexa(size_t n, char **str)
{
	char	*hexa;
	size_t	len;
	size_t	i;

	hexa = "0123456789abcdef";
	len = ft_hexalong_len(n);
	i = 0;
	while (i < len)
	{
		(*str)[i] = hexa[n / ft_hexalong_multi(len - i)];
		n = n % ft_hexalong_multi(len - i);
		i++;
	}
	(*str)[i] = '\0';
	return ;
}

int	ft_printptr(va_list list)
{
	size_t	u;
	char	*str;
	int		n;
	int		m;
	int		tot;

	u = va_arg(list, size_t);
	if (u == 0)
		return (ft_putstr_int("(nil)"));
	str = malloc(sizeof(char) * 17);
	if (str == NULL)
		return (-1);
	ft_convlonghexa(u, &str);
	n = ft_putstr_int("0x");
	if (n == -1)
		return (n);
	m = ft_putstr_int(str);
	if (m == -1)
		return (m);
	tot = m + n;
	free(str);
	return (tot);
}
