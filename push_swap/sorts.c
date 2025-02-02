/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/02 18:58:34 by pamallet         ###   ########.fr       */
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
	int	cheap_b;

	i = 0;
	nb_ops = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //ok
	/* printf("cheap_b: %d\n", cheap_b); */
	while (b->arr[i] != cheap_b) //ok
		i++;
	if (i <= b->len / 2)
		nb_ops = i;
	else
		nb_ops = b->len - i;
	/* printf("nb_ops(b_sort): %d\n", nb_ops); //why 1? instead of 2 */
	return (nb_ops);
}

int	cheap_index_from_a_to_b(t_data *data)
{
	int	i;
	int	tmp;
	int	cheap_i;
	int	count;

	i = 0;
	tmp = data->a.len; //max
	cheap_i = i;
	while (i < data->a.len)
	{
		count = 0;
		if (i <= data->a.len / 2)
			count += i;
		else
			count += data->a.len - i; //ra / rra counter: OK
		count += desc_sort_count(data->a.arr[i], &data->b); //total ops(!opti)
		if (count < tmp)
		{
			tmp = count;
			cheap_i = i;
		}
		i++;
	}
	return (cheap_i);
}

void	count_from_a_to_b(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = data->a.len; //max
	while (i < data->a.len) //a_to_b sort
	{
		data->nb_ops = 0;
		if (i <= data->a.len / 2)
			data->nb_ops += i;
		else
			data->nb_ops += data->a.len - i;
		/* printf("[%d] = %d, nb_ops(a sort): %d\n", i, data->a.arr[i], data->nb_ops); */
		data->nb_ops += desc_sort_count(data->a.arr[i], &data->b);
		/* printf("total nb_ops(a + b sort): %d\n\n", data->nb_ops); */
		if (data->nb_ops < tmp)
			tmp = data->nb_ops;
		i++;
	}
	data->nb_ops = tmp;
	printf("nb_ops: %d\n", data->nb_ops);
}

void	count_a_three_sort(t_data *data)
{
	if ((data->a.len != 3)
		|| (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] < data->a.arr[2]))
		return ;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2])
		data->nb_ops = 1;
	else if (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] > data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		data->nb_ops = 1;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2]
		&& data->a.arr[0] < data->a.arr[2])
		data->nb_ops = 1;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] > data->a.arr[2])
		data->nb_ops = 2;
	else
		data->nb_ops = 2;
}

void	count_cheap_total_ops(t_data *data, int is_first)
{
	if (data->a.len > 3 && is_first)
		count_from_a_to_b(data);
	else if (data->a.len == 3)
		count_a_three_sort(data);
	/* else */
	/* 	count_from_b_to_a(data); */
}

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

	cheap_index_a = cheap_index_from_a_to_b(data);
	while (data->a.arr[0] != data->a.arr[cheap_index_a])
	{
		if (cheap_index_a <= (data->a.len / 2))
			rotate(&data->a, data);
		else
			rev_rotate(&data->a, data);
	}
}

void	init_log_ops(t_data *data)
{
	data->log_index = 0;
	data->log_ops = (char **)malloc((data->nb_ops + 1) * sizeof(char *));
	if (!data->log_ops) //free?
		handle_error(ERROR_MSG);
}

void	ft_free_log_ops(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->log_index)
		free(data->log_ops[i]);
	free(data->log_ops);
}

void	print_log_ops(t_data *data)
{
	int	i;
	int	n;
	int	m;

	i = -1;
	n = 0;
	//opti for rr/rrr(nested loop?), strcmp(data->log_ops[i], "ra")
	
	while (++i < data->log_index)
		printf("[%d] %s\n", i, data->log_ops[i]);
}

void	a_to_b_sort(t_data *data)
{
	data->nb_ops = 0;
	count_cheap_total_ops(data, 1); //ok for 1rst sort
	init_log_ops(data); //ok
	rotate_to_top_a(data); //ra/rra, inf loop when changing elems
	desc_sort_b(data); //rb/rrb, ok
	data->log_ops[data->nb_ops] = 0; //ok
	printf("log_index: %d\n", data->log_index); //ok
	print_log_ops(data); //ok, but improve
	ft_free_log_ops(data); //ok
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
		printf("\n---three_sort---\n");
		printf("nb_ops: %d\n", data->nb_ops);
		printf("log_index: %d\n", data->log_index); //ok
		print_log_ops(data); //ok
		ft_free_log_ops(data); //ok
	}
	//while (data->b.len > 0)
		//b_to_a_sort(data);
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
