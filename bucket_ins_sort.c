/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_ins_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:38:26 by cydupire          #+#    #+#             */
/*   Updated: 2026/01/06 17:15:46 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_nb_buckets(t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->size_a / i)
	{
		if (data->size_a / i == i)
			return (i);
		i++;
	}
	return (0);
}

int	find_nb_buckets(t_data *data)
{
	size_t	i;

	i = 1;
	while (i * i <= data->size_a)
		i++;
	return (i - 1);
}

// trouver elements a mettre dans le bucket
// pointeur qui parcourt la liste : enregistre dans un tableau la valeur la plus grande qui n'est pas deja presente dans le tableau
// quand taille tableau = nb de bucket renvoyer tableau
// faire tourner la liste jusqu'a trouver les elements du tableau
// verifier si rotate ou revrot est le plus approprie pour aller chercher l'element le plus proche

void	bucket_ins_sort(t_data *data, t_bench *bench)
{
	t_list *ptr_a;
	long long i;
	long long size;

	ptr_a = data->a;
	i = 0;
	size = data->size_a;
	while (is_stack_sorted(data) != 1)
	{
	}
	return ;
}