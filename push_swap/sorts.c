/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/01 22:55:53 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheap_index_from_b(int top_a, t_stack *b) //a[0], b
{
	int	i;
	int	cheap;
	int	cheap_i;

	i = 0;
	cheap = top_a;
	cheap_i = 0;
	while (i < b->len)
	{
		if ((top_a - b->arr[i]) < cheap && (top_a - b->arr[i]) > 0) //max - shorter
		{
			cheap = top_a - b->arr[i];
			cheap_i = i;
		}
		if (cheap == 1)
			return (cheap_i);
		i++;
	}
	if (i == b->len && cheap_i == 0) //new min, above biggest(sorted bef!)
		cheap_i = 0;
	return (cheap_i);
}

int	desc_sort_count(int top_a, t_stack *b)
{
	int	i;
	int	nb_ops;
	int	cheap_elem;

	i = 0;
	nb_ops = 0;
	cheap_elem = b->arr[cheap_index_from_b(top_a, b)];
	while (b->arr[i] != cheap_elem)
	{
		nb_ops = 0; //1
		if (i <= b->len / 2)
			nb_ops += i;
		else
			nb_ops += b->len - i;
		i++;
	}
	return (nb_ops);
}

int	cheap_index_from_a_to_b(t_data *data)
{
	int	i;
	int	save;
	int	save_i;

	i = 0;
	save = data->a.len; //max
	save_i = i;
	while (i < data->a.len)
	{
		data->nb_ops = 0;
		if (i <= data->a.len / 2)
			data->nb_ops += i;
		else
			data->nb_ops += data->a.len - i; //ra / rra counter: OK
		data->nb_ops += desc_sort_count(data->a.arr[i], &data->b); //total ops(!opti)
		printf("nb_ops: %d\n", data->nb_ops);
		if (data->nb_ops < save)
		{
			save = data->nb_ops;
			save_i = i;
		}
		i++;
	}
	data->nb_ops = save;
	return (save_i);
}

void	desc_sort_b(t_data *data, int cheap_index_a)
{
	int	cheap_a;
	int	cheap_b;
	int	cheap_index_b;

	cheap_a = data->a.arr[cheap_index_a];
	cheap_index_b = cheap_index_from_b(cheap_a, &data->b);
	cheap_b = data->b.arr[cheap_index_b];
	while (data->b.arr[0] != cheap_b)
	{
		if (cheap_index_b <= (data->b.len / 2))
			rotate(&data->b, data->log_ops, data->log_index);
		else
			rev_rotate(&data->b, data->log_ops, data->log_index);
	}
}

void	rotate_to_top_a(t_data *data, int cheap_index_a)
{
	while (data->a.arr[0] != data->a.arr[cheap_index_a])
	{
		if (cheap_index_a <= (data->a.len / 2))
			rotate(&data->a, data->log_ops, data->log_index);
		else
			rev_rotate(&data->a, data->log_ops, data->log_index);
	}
}

void	ft_free_log_ops(char **log_ops)
{
	int	i;

	i = -1;
	while (log_ops[++i])
		free(log_ops[i]);
	free(log_ops);
}

void	print_log_ops(char **log_ops)
{
	int	i;

	i = -1;
	while (log_ops[++i])
		printf("[%d] %s\n", i, log_ops[i]);
}

void	a_to_b_sort(t_data *data)
{
	int	cheap_index_a;

	data->nb_ops = 0;
	data->log_index = 0;
	cheap_index_a = cheap_index_from_a_to_b(data); //count nb_ops
	data->log_ops = (char **)malloc((data->nb_ops + 1) * sizeof(char *)); //not count push!
	if (!data->log_ops) //free?
		handle_error(ERROR_MSG);
	rotate_to_top_a(data, cheap_index_a); //inf ra with 19 elems?
	desc_sort_b(data, cheap_index_a);
	data->log_ops[data->nb_ops] = 0; //ok
	print_log_ops(data->log_ops); //ok
	ft_free_log_ops(data->log_ops); //ok
	push(&data->a, &data->b); //ok
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
		push(&data->a, &data->b); //pb
		push(&data->a, &data->b); //pb
		first_desc_sort_b(&data->b); //sb
		while (data->a.len > 3)
			a_to_b_sort(data);
	}
	if (data->a.len == 3)
		three_sort(data);
	//while (data->b.len > 0)
		//b_to_a_sort(data);
}

void	three_sort(t_data *data)
{
	printf("\n");
	if ((data->a.len != 3)
		|| (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] < data->a.arr[2]))
		return ;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2])
		rotate(&data->a, data->log_ops, data->log_index);
	else if (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] > data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		rev_rotate(&data->a, data->log_ops, data->log_index);
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2]
		&& data->a.arr[0] < data->a.arr[2])
		swap(&data->a);
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] > data->a.arr[2])
	{
		swap(&data->a);
		rev_rotate(&data->a, data->log_ops, data->log_index);
	}
	else
	{
		swap(&data->a);
		rotate(&data->a, data->log_ops, data->log_index);
	}
}
