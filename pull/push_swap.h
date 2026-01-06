/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclairot <bclairot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:46:51 by bclairot          #+#    #+#             */
/*   Updated: 2025/12/16 16:46:51 by bclairot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// TODO delete before submission and replace printf by ft_printf
# include <stdio.h>

typedef struct s_list
{
	long long		value;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	t_list			*a; // @CyDupire c'est possible de faire ca si tu veux je sais pas si ca t'arranges ou pas au pire restore
	t_list			*b;
	t_list			*end_a;
	t_list			*end_b;
	int				size_a;
	int				size_b;
	int 			strategy;
	float 			disorder_rate;
	int 			bench;
}					t_data;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

char				**ft_split(char const *s);

void				error_handler(char *str);

t_list				*ft_lstnew(long long value);
void				ft_lstdelone(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
// TODO maybe rename "new" variable look weird on my IDE,
void				ft_lstadd_front(t_list **lst, t_list *new);
// TODO maybe rename "new" variable look weird on my IDE,
void				list_init_element(t_data *data, const char *str);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfirst(t_list *lst); // a voir ?

int					ft_isspace(char c);
int					is_split_needed(char *str);
void				parsing(int argc, char *argv[]);
long long			ft_atoi(const char *str);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				init_list(int argc, char *argv[], t_data *data, t_bench *bench);
void				select_strategy(t_data *data,char *str);

int					is_a_flags(char *str);
int 				init_flags(int argc,char *argv[],t_data *data);

float				compute_disorder(t_list *stack);

void 				show_bench(t_data data, t_bench bench);

// pour test op
void	ft_op_swap(t_list **lst_a, t_list **lst_b, char which_stack);
void	ft_op_push(t_list **lst_a, t_list **lst_b, char which_stack);
void	ft_op_rotate(t_list **lst_a, t_list **lst_b, char which_stack);
void	ft_op_reverse_rotate(t_list **lst_a, t_list **lst_b, char which_stack);


// pour bubble sort
int		ft_is_stack_sorted(t_data *data);
void	ft_bubble_sort(t_data *data);

#endif
