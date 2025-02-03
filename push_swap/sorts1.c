/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/03 19:45:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_sort_b(t_data *data)
{
	int	cheap_index_a;
	int	cheap_a;
	int	cheap_index_b;
	int	cheap_b;

	cheap_index_a = cheap_index_from_a_to_b(data);
	cheap_a = data->a.arr[cheap_index_a];
	cheap_index_b = cheap_index_from_b(cheap_a, &data->b);
	cheap_b = data->b.arr[cheap_index_b];
	while (data->b.arr[0] != cheap_b)
	{
		if (cheap_index_b <= (data->b.len / 2))
			rotate(&data->b, data);
		else
			rev_rotate(&data->b, data);
	}
}

void	rotate_to_top_a(t_data *data)
{
	int	cheap_index_a;
	int	cheap_a;

	cheap_index_a = cheap_index_from_a_to_b(data);
	cheap_a = data->a.arr[cheap_index_a];
	ft_printf("cheap_i of a: %d\n", cheap_index_a);
	while (data->a.arr[0] != cheap_a)
	{
		if (cheap_index_a <= (data->a.len / 2))
			rotate(&data->a, data);
		else
			rev_rotate(&data->a, data);
	}
}

void	a_to_b_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 1); //ok for 1rst sort, reduce if rr / rrr TODO 2
	init_log_ops(data); //ok
	rotate_to_top_a(data); //ra/rra, ok
	desc_sort_b(data); //rb/rrb, ok
	data->log_ops[data->nb_ops] = 0; //ok
	ft_printf("log_index: %d\n", data->log_index); //ok
	print_log_ops(data); //ok
	ft_free_log_ops(data); //ok
	push(&data->a, &data->b); //a.len-- ok
	printf("\n");
}

void	first_desc_sort_b(t_stack *stk)
{
	if (stk->arr[0] < stk->arr[1])
		swap(stk);
}

void	turk_sort(t_data *data)
{
	if (data->a.len > 3)
	{
		push(&data->a, &data->b); //ok
		push(&data->a, &data->b); //ok
		first_desc_sort_b(&data->b); //ok
		while (data->a.len > 3)
			a_to_b_sort(data);
	}
	if (data->a.len == 3)
	{
		data->nb_ops = 0; //ok
		count_cheap_total_ops(data, 0); //ok
		init_log_ops(data); //ok
		three_sort(data); //ok
		ft_printf("\n---three_sort---\n");
		/* ft_printf("nb_ops: %d\n", data->nb_ops); */
		ft_printf("log_index: %d\n", data->log_index); //ok
		print_log_ops(data); //ok
		ft_free_log_ops(data); //ok
	}
	/* while (data->b.len > 0) */
	/* 	b_to_a_sort(data); */
}

void	three_sort(t_data *data)
{
	if ((data->a.len != 3)
		|| (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] < data->a.arr[2]))
		return ;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2])
		rotate(&data->a, data);
	else if (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] > data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		rev_rotate(&data->a, data);
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2]
		&& data->a.arr[0] < data->a.arr[2])
		swap(&data->a);
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] > data->a.arr[2])
	{
		swap(&data->a);
		rev_rotate(&data->a, data);
	}
	else
	{
		swap(&data->a);
		rotate(&data->a, data);
	}
}
