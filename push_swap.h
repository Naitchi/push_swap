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
	unsigned int	index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	t_list			*a;
	t_list			*b;
	t_list			*end_a;
	t_list			*end_b;
	int				size_a;
	int				size_b;
	int				strategy;
	float			disorder_rate;
	int				bench;
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

typedef struct s_buckets
{
	int				buckets;
	int				values;
	int				mod;
	int				*array;
}					t_buckets;

char				**ft_split(char const *s);
int					ft_printf(const char *str, ...);
void				error_handler(char *str);
void				list_init_element(t_data *data, const char *str);

t_list				*ft_lstnew(long long value);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstfirst(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_elmt);
void				ft_lstclear(t_list **lst);

int					ft_isspace(char c);
int					is_split_needed(char *str);
void				parsing(int argc, char *argv[]);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_atoi(const char *str);
void				ft_bzero(void *s, int n);

void				init_list(int argc, char *argv[], t_data *data,
						t_bench *bench);
void				select_strategy(t_data *data, char *str);

int					is_a_flag(char *str);
int					init_flags(int argc, char *argv[], t_data *data);

float				compute_disorder(t_list *stack);

void				show_bench(t_data data, t_bench bench);

void				op_swap(t_data *data, char which_stack, t_bench *bench);
void				op_push(t_data *data, char which_stack, t_bench *bench);
void				op_rotate(t_data *data, char which_stack, t_bench *bench);
void				op_reverse_rotate(t_data *data, char which_stack,
						t_bench *bench);

int					is_stack_sorted(t_data *data);
void				bubble_sort(t_data *data, t_bench *bench);
void				bucket_ins_sort(t_data *data, t_bench *bench);
void				update_buckets(t_data *data, t_buckets *buck);
int					find_nb_buckets(t_data *data);
int					is_value_present(int value, int *array, int size);
int					rot_or_rev_buck(t_data *data, t_buckets *buck);
int					find_min(t_list *lst);
int					find_max(t_list *lst);

int					rot_or_rev(t_data *data, unsigned int index);

void				radix(t_data *data, t_bench *bench);

void				give_index(t_data *data);

void				print_stack(t_list *stack);

#endif