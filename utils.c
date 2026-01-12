/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:40:49 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/12 15:19:05 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)s = 0;
		i++;
		s++;
	}
	return ;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && (rslt > (INT_MAX - (str[i] - '0')) / 10))
			return (INT_MAX);
		if (sign == -1 && (rslt > (-(INT_MIN + (str[i] - '0'))) / 10))
			return (INT_MIN);
		rslt = rslt * 10 + (str[i] - '0');
		i++;
	}
	return (rslt * sign);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	next = temp->next;
	while (next)
	{
		free(temp);
		temp = next;
		next = temp->next;
	}
	free(temp);
	*lst = NULL;
}

int	is_stack_sorted(t_data *data)
{
	t_list	*ptr;

	ptr = data->a;
	while (ptr->next != NULL)
	{
		if (ptr->value < ptr->next->value)
			ptr = ptr->next;
		else
			return (0);
	}
	if (data->b != NULL)
		return (0);
	else
		return (1);
}
