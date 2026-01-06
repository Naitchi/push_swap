/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:11:55 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/19 15:42:23 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_len(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while ((n / 10) != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static int	ft_multi(int len)
{
	int	multi;

	multi = 1;
	while (len > 1)
	{
		multi = multi * 10;
		len--;
	}
	return (multi);
}

static char	*ft_conv(char *str, int n, int len)
{
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = n * -1;
		neg = 1;
	}
	while (i < (len))
	{
		str[i] = ((n / ft_multi(len - i)) + '0');
		n = n % ft_multi(len - i);
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_int_min(char *str)
{
	int		i;
	char	*int_min;

	i = 0;
	int_min = "-2147483648";
	while (int_min[i] != '\0')
	{
		str[i] = int_min[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = ft_check_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_int_min(str);
		return (str);
	}
	str = ft_conv(str, n, len);
	return (str);
}
