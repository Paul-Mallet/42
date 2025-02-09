/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 17:50:13 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_sort_b(t_data *data)
{
	int	cheap_a;
	int	cheap_index_b;
	int	cheap_b;

	cheap_a = data->a.arr[0];
	cheap_index_b = cheap_index_from_b(cheap_a, data);
	cheap_b = data->b.arr[cheap_index_b];
	while (data->b.arr[0] != cheap_b)
	{
		if (cheap_index_b <= (data->b.len / 2))
			rotate(&data->b, data, 0);
		else
			rev_rotate(&data->b, data, 0);
	}
}

void	rotate_to_top_a(t_data *data, int is_from_a_to_b)
{
	int	cheap_index_a;
	int	cheap_a;

	if (is_from_a_to_b)
	{
		cheap_index_a = cheap_index_from_a_to_b(data, INDEX);
		cheap_a = data->a.arr[cheap_index_a];
	}
	else
	{
		cheap_index_a = cheap_index_from_a(data->b.arr[0], data);
		cheap_a = data->a.arr[cheap_index_a];
	}
	while (data->a.arr[0] != cheap_a)
		print_rotate_to_top_a(data, cheap_index_a, is_from_a_to_b);
}

void	a_to_b_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 1, 0);
	init_log_ops(data);
	rotate_to_top_a(data, 1);
	desc_sort_b(data);
	data->log_ops[data->len_log] = 0;
	print_log_ops(data);
	ft_free_log_ops(data);
	push(&data->a, &data->b);
}

void	b_to_a_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 0, 1);
	rotate_to_top_a(data, 0);
	push(&data->b, &data->a);
}

void	turk_sort(t_data *data)
{
	if (data->a.len > 3)
	{
		push(&data->a, &data->b);
		push(&data->a, &data->b);
		first_desc_sort_b(&data->b);
		while (data->a.len > 3)
			a_to_b_sort(data);
	}
	if (data->a.len == 3)
	{
		data->nb_ops = 0;
		count_cheap_total_ops(data, 0, 0);
		init_log_ops(data);
		three_sort(data);
		print_log_ops(data);
		ft_free_log_ops(data);
	}
	if (data->a.len == 2)
		two_sort(data);
	while (data->b.len > 0)
		b_to_a_sort(data);
	if (data->a.arr[0] != 1)
		final_asc_sort_a(data);
}
