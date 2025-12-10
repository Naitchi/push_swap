/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:10:27 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/10 11:20:06 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include <stdlib.h>

typedef struct s_list
{
	long long		value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list	*ft_lstnew(long long value);
void	ft_lstdelone(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	list_check_double(t_list *lst, long long nbr);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *lst); // a voir ?

# endif
