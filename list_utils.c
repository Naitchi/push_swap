/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:06:18 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 13:25:47 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

t_list	*ft_lstnew(long long value)
{
    t_list	*new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
	new->prev = NULL;
    return (new);
}

void	ft_lstdelone(t_list *lst)
{
    if (!lst)
        return ;
    free(lst);
}

t_list	*ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

// peut-etre utile a supprimer sinon
t_list	*ft_lstfirst(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->prev)
        lst = lst->prev;
    return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list	*ptr;

    if (!new)
        return ;
    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    ptr = ft_lstlast(*lst);
    ptr->next = new;
	new->prev = ptr;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!new)
        return ;
	(*lst)->prev = new;
    new->next = *lst;
    *lst = new;
}

void	list_check_double(t_list *lst, long long nbr)
{
    while (lst)
    {
        if (lst->value == nbr)
            error_handler(0);
        lst = lst->next;
    }
}
