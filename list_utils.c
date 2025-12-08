/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:06:18 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/08 18:12:29 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long long *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	elem = ft_lstlast(*lst);
	elem->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
