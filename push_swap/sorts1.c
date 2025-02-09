/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 12:51:18 by pamallet         ###   ########.fr       */
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

void	rotate_to_top_a(t_data *data, int is_from_a_to_b) //TODO
{
	int	cheap_index_a;
	int	cheap_a;

	if (is_from_a_to_b)
	{
		cheap_index_a = cheap_index_from_a_to_b(data);
		cheap_a = data->a.arr[cheap_index_a];
	}
	else
	{
		cheap_index_a = cheap_index_from_a(data->b.arr[0], data);
		cheap_a = data->a.arr[cheap_index_a];
	}
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
				rev_rotate(&data->a, data, 0);
			else
			{
				rev_rotate(&data->a, data, 1);
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
	count_cheap_total_ops(data, 1, 0);
	/* ft_printf("nb_ops: %d, len_log: %d\n", data->nb_ops, data->len_log); */
	init_log_ops(data);
	/* ft_printf("log_index(bef rot a): %d\n", data->log_index); */
	rotate_to_top_a(data, 1);
	/* ft_printf("log_index(aft rot a): %d\n", data->log_index); */
	desc_sort_b(data);
	/* ft_printf("log_index(aft rot b): %d\n", data->log_index); */
	data->log_ops[data->len_log] = 0;
	/* ft_printf("log_index: %d\n", data->log_index); */ 
	print_log_ops(data);
	ft_free_log_ops(data);
	push(&data->a, &data->b);
	/* ft_printf("A: "); */
	/* print_stack(&data->a); */
	/* ft_printf("\nB: "); */
	/* print_stack(&data->b); */
	/* ft_printf("\n"); */
}

void	b_to_a_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 0, 1);
	rotate_to_top_a(data, 0);
	push(&data->b, &data->a);
	/* ft_printf("A: "); */
	/* print_stack(&data->a); */
	/* ft_printf("\nB: "); */
	/* print_stack(&data->b); */
	/* ft_printf("\n"); */
}

void	three_sort(t_data *data)
{
	if ((data->a.len != 3)
		|| (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] < data->a.arr[2]))
		return ;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		rotate(&data->a, data, 0);
	else if (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] > data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		rev_rotate(&data->a, data, 0);
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
			ft_printf("r%c\n", data->a.name);
		}
		else
		{
			rev_rotate(&data->a, data, 1);
			ft_printf("rr%c\n", data->a.name);
		}
	}
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
		/* ft_printf("\n---three_sort---\n"); */
		print_log_ops(data);
		/* ft_printf("A: "); */
		/* print_stack(&data->a); */
		/* ft_printf("\nB: "); */
		/* print_stack(&data->b); */
		/* ft_printf("\n"); */
		ft_free_log_ops(data);
	}
	while (data->b.len > 0)
	 	b_to_a_sort(data);
	if (data->a.arr[0] != 1)
		final_asc_sort_a(data);
	/* ft_printf("A: "); */
	/* print_stack(&data->a); */
	/* ft_printf("\nB: "); */
	/* print_stack(&data->b); */
	/* ft_printf("\n"); */
}
