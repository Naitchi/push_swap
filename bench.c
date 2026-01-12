/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cydupire <cydupire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:41:16 by bclairot          #+#    #+#             */
/*   Updated: 2026/01/12 12:16:53 by cydupire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putll(long long nbr)
{
	char	c;

	c = 0;
	if (nbr < 0)
	{
		write(2, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10 != 0)
		ft_putll(nbr / 10);
	c = nbr % 10 + '0';
	write(2, &c, 1);
}

void	print_parameters(t_data data)
{
	write(2, "[bench] disorder: ", 18);
	ft_putll((int)(data.disorder_rate * 100));
	write(2, ".", 1);
	ft_putll((int)((data.disorder_rate * 100 - (int)(data.disorder_rate * 100))
			* 100));
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	if (data.strategy == 1)
		write(2, "Simple / O(n^2)\n", 16);
	else if (data.strategy == 2)
		write(2, "Medium / O(n√n)\n", 18);
	else if (data.strategy == 3)
		write(2, "Complex / O(n log n)\n", 21);
	else if (data.strategy == 4)
	{
		write(2, "Adaptive / ", 11);
		if (data.disorder_rate < 0.2)
			write(2, "O(n^2)\n", 7);
		else if (data.disorder_rate >= 0.2 && data.disorder_rate < 0.5)
			write(2, "O(n√n)\n", 7);
		else
			write(2, "O(n log n)\n", 11);
	}
}

int	total_ops(t_bench bench)
{
	int	total;

	total = 0;
	total += bench.sa;
	total += bench.sb;
	total += bench.ss;
	total += bench.pa;
	total += bench.pb;
	total += bench.ra;
	total += bench.rb;
	total += bench.rr;
	total += bench.rra;
	total += bench.rrb;
	total += bench.rrr;
	return (total);
}

void	print_result_numbers(t_bench bench)
{
	write(2, "[bench] total_ops: ", 19);
	ft_putll(total_ops(bench));
	write(2, "\n[bench] sa: ", 13);
	ft_putll(bench.sa);
	write(2, " sb: ", 5);
	ft_putll(bench.sb);
	write(2, " ss: ", 5);
	ft_putll(bench.ss);
	write(2, " pa: ", 5);
	ft_putll(bench.pa);
	write(2, " pb: ", 5);
	ft_putll(bench.pb);
	write(2, "\n[bench] ra: ", 13);
	ft_putll(bench.ra);
	write(2, " rb: ", 5);
	ft_putll(bench.rb);
	write(2, " rr: ", 5);
	ft_putll(bench.rr);
	write(2, " rra: ", 6);
	ft_putll(bench.rra);
	write(2, " rrb: ", 6);
	ft_putll(bench.rrb);
	write(2, " rrr: ", 6);
	ft_putll(bench.rrr);
	write(2, "\n", 1);
}

void	show_bench(t_data data, t_bench bench)
{
	if (data.bench)
	{
		print_parameters(data);
		print_result_numbers(bench);
	}
}
