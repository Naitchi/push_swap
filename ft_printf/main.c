/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:34:46 by cydupire          #+#    #+#             */
/*   Updated: 2025/12/09 09:32:06 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	char	*ptr2;
	int		res1;
	int		res2;

	ptr = NULL;
	res1 = ft_printf("char  %c %c %c \n", 'M', '1', 0);
	printf("res : %i\n", res1);
	res2 = printf("char  %c %c %c \n", 'M', '1', 0);
	printf("res : %i\n", res2);

	res1 = ft_printf("str %s %s %s %s \n", "M", "miaou", "", (char *) NULL);
	printf("res : %i\n", res1);
	res2 = printf("str %s %s %s %s \n", "M", "miaou", "", (char *) NULL);
	printf("res : %i\n", res2);

	res1 = ft_printf("decimal %d %d %d %d %d \n", 12, -1, 0, 'c', -2147483647);
	printf("res : %i\n", res1);
	res2 = printf("decimal %d %d %d %d %d \n", 12, -1, 0, 'c', -2147483647);
	printf("res : %i\n", res2);

	res1 = ft_printf("int %i %i %i %i %i \n", 12, -1, 0, 'c', -2147483647);
	printf("res : %i\n", res1);
	res2 = printf("int %i %i %i %i %i \n", 12, -1, 0, 'c', -2147483647);
	printf("res : %i\n", res2);

	res1 = ft_printf("unsigned %u %u %u %u %u \n", 12, -1, 0, 'c', -2147483647);
	printf("res : %i\n", res1);
	res2 = printf("unsigned %u %u %u %u %u \n", 12, -1, 0, 'c', -2147483647);
	printf("res : %i\n", res2);

	res1 = ft_printf("hexa_low %x %x %x %x %x \n", 555, 0, -1, 'c', 2147483647);
	printf("res : %i\n", res1);
	res2 = printf("hexa_low %x %x %x %x %x \n", 555, 0, -1, 'c', 2147483647);
	printf("res : %i\n", res2);

	res1 = ft_printf("hexa_up %X %X %X %X %X \n", 555, 0, -1, 'c', 2147483647);
	printf("res : %i\n", res1);
	res2 = printf("hexa_up %X %X %X %X %X \n", 555, 0, -1, 'c', 2147483647);
	printf("res : %i\n", res2);

	res1 = ft_printf("ptr %p %p %p \n", NULL, &ptr, &ptr2);
	printf("res : %i\n", res1);
	res2 = printf("ptr %p %p %p \n", NULL, &ptr, &ptr2);
	printf("res : %i\n", res2);

	res1 = ft_printf("double%% 100%% bla%%bla \n");
	printf("res : %i\n", res1);
	res2 = printf("double%% 100%% bla%%bla \n");
	printf("res : %i\n", res2);

	res2 = printf(NULL);
	printf("res : %i\n", res2);
	res1 = ft_printf(NULL);
	printf("res : %i\n", res1);

	return (0);
}
