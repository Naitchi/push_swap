/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:06:18 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/08 20:07:01 by bclairot         ###   ########.fr       */
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

void	list_check_double(t_list *lst, long long nbr)
{
    while (lst)
    {
        if (lst->value == nbr)
            error_handler(0);
        lst = lst->next;
    }
}
