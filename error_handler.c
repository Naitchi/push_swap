/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:18:49 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/11 13:57:51 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO modifier les parametres pour free aussi ?
void	error_handler(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "Error\n";
	while (str[i])
		i++;
	write(2, str, i);
	exit(1);
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