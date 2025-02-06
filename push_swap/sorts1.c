/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/06 12:57:39 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	desc_sort_b(t_data *data)
{
	int	cheap_index_a;
	int	cheap_a;
	int	cheap_index_b;
	int	cheap_b;

	cheap_index_a = cheap_index_from_a_to_b(data); //TODO must be a[3] = 8
	cheap_a = data->a.arr[cheap_index_a];
	ft_printf("cheap_i of a: %d\n", cheap_index_a);
	cheap_index_b = cheap_index_from_b(cheap_a, &data->b);
	cheap_b = data->b.arr[cheap_index_b];
	ft_printf("cheap_i of b: %d\n", cheap_index_b);
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
		cheap_index_a = cheap_index_from_a_to_b(data);
		cheap_a = data->a.arr[cheap_index_a];
	}
	else //from_b_to_a
	{
		cheap_index_a = cheap_index_from_a(data->b.arr[0], &data->a); //always b.arr[0]
		cheap_a = data->a.arr[cheap_index_a];
	}
	/* ft_printf("cheap_i of a: %d\n", cheap_index_a); //[3] */
	while (data->a.arr[0] != cheap_a)
	{
		if (cheap_index_a <= (data->a.len / 2))
		{
			if (is_from_a_to_b)
				rotate(&data->a, data, 0);
			else
			{
				rotate(&data->a, data, 1);
				ft_printf("r%c\n", data->a.name);
			}
		}
		else
		{
			if (is_from_a_to_b)
				rev_rotate(&data->a, data, 0); //TODO
			else
			{
				rev_rotate(&data->a, data, 1); //TODO
				ft_printf("rr%c\n", data->a.name);
			}
		}
	}
}

void	print_log_ops_easy(t_data *data)
{
	int	i;

	i = 0;
	while (data->log_ops[i])
	{
		ft_printf("[%d] %s\n", i, data->log_ops[i]);
		i++;
	}
}

void	a_to_b_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 1, 0); //ok, nb_ops + len_log
	ft_printf("nb_ops:%d, len_log: %d\n", data->nb_ops, data->len_log);
	init_log_ops(data); //ok, log_index = 2, len_log = 2
	/* ft_printf("log_index(bef rot a): %d\n", data->log_index); //ok */
	rotate_to_top_a(data, 1); //ra/rra, ok
	/* ft_printf("log_index(aft rot a): %d\n", data->log_index); //ok */
	desc_sort_b(data); //rb/rrb, log_index++ (+1)
	/* ft_printf("log_index(aft rot b): %d\n", data->log_index); //ok */
	data->log_ops[data->len_log] = 0; //ok
	/* ft_printf("log_index: %d\n", data->log_index); //ok */
	print_log_ops_easy(data); //ok
	print_log_ops(data); //ok
	ft_free_log_ops(data); //ok
	push(&data->a, &data->b); //a.len-- ok
	print_stack(&data->a);
	print_stack(&data->b);
	ft_printf("\n");
}

void	b_to_a_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 0, 1); //nb_ops 
	ft_printf("nb_ops:%d\n", data->nb_ops);
	rotate_to_top_a(data, 0); //ra/rra 
	push(&data->b, &data->a); //b.len-- ok
	print_stack(&data->a);
	print_stack(&data->b);
	ft_printf("\n");
}

void	three_sort(t_data *data)
{
	if ((data->a.len != 3)
		|| (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] < data->a.arr[2]))
		return ;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2])
		rotate(&data->a, data, 1);
	else if (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] > data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		rev_rotate(&data->a, data, 1);
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2]
		&& data->a.arr[0] < data->a.arr[2])
		swap(&data->a);
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] > data->a.arr[2])
	{
		swap(&data->a);
		rev_rotate(&data->a, data, 0);
	}
	else
	{
		swap(&data->a);
		rotate(&data->a, data, 0);
	}
}

void	final_asc_sort_a(t_data *data)
{
	int	cheap_index_a;

	cheap_index_a = -1;
	while (++cheap_index_a < data->a.len)
	{
		if (data->a.arr[cheap_index_a] == 1)
			break ;
	}
	while (data->a.arr[0] != 1)
	{
		if (cheap_index_a <= (data->a.len / 2))
		{
			rotate(&data->a, data, 1);
			ft_printf("r%c\n", data->a.name); //ra
		}
		else
		{
			rev_rotate(&data->a, data, 1);
			ft_printf("rr%c\n", data->a.name); //rra
		}
	}
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
		count_cheap_total_ops(data, 0, 0); //ok
		init_log_ops(data); //ok
		three_sort(data); //ok
		ft_printf("\n---three_sort---\n");
		ft_printf("nb_ops: %d\n", data->nb_ops);
		ft_printf("log_index: %d\n", data->log_index); //ok
		print_log_ops(data); //ok
		ft_free_log_ops(data); //ok
	}
	while (data->b.len > 0)
	 	b_to_a_sort(data);
	if (data->a.arr[0] != 1)
		final_asc_sort_a(data);
}
