/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:25:34 by cydupire          #+#    #+#             */
/*   Updated: 2025/11/28 10:33:47 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_check_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while ((n / 10) != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static unsigned int	ft_multi(unsigned int len)
{
	unsigned int	multi;

	multi = 1;
	while (len > 1)
	{
		multi = multi * 10;
		len--;
	}
	return (multi);
}

static char	*ft_conv(char *str, unsigned int n, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < (len))
	{
		str[i] = ((n / ft_multi(len - i)) + '0');
		n = n % ft_multi(len - i);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_unsitoa(unsigned int n)
{
	unsigned int	len;
	char			*str;

	len = ft_check_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_conv(str, n, len);
	return (str);
}
