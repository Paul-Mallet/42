/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:39:37 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 12:46:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	above_bigger(t_stack *b)
{
	int	i;
	int	big_i;
	int	bigger;

	i = 0;
	big_i = 0;
	bigger = 0;
	while (i < b->len)
	{
		if (b->arr[i] > bigger)
		{
			bigger = b->arr[i];
			big_i = i;
		}
		i++;
	}
	return (big_i);
}

void	desc_sort_bigger(t_data *data)
{
	int	bigger_b;
	int	bigger_i;

	bigger_i = above_bigger(&data->b);
	bigger_b = data->b.arr[bigger_i];
	while (data->b.arr[0] != bigger_b)
	{
		if (bigger_i <= data->b.len / 2)
		{
			rotate(&data->b, data, 1);
			ft_printf("r%c\n", data->b.name);
		}
		else
		{
			rev_rotate(&data->b, data, 1);
			ft_printf("rr%c\n", data->b.name);
		}
	}
}

int	cheap_index_from_b(int top_a, t_data *data)
{
	int	i;
	int	cheap;
	int	cheap_i;

	i = 0;
	cheap = data->a.capacity;
	cheap_i = data->a.capacity;
	while (i < data->b.len)
	{
		if ((top_a - data->b.arr[i]) < cheap && (top_a - data->b.arr[i]) > 0)
		{
			cheap = top_a - data->b.arr[i];
			cheap_i = i;
		}
		if (cheap == 1)
			return (cheap_i);
		i++;
	}
	if (i == data->b.len && cheap_i == data->a.capacity)
		cheap_i = above_bigger(&data->b);
	return (cheap_i);
}

int	cheap_index_from_a(int top_b, t_data *data)
{
	int	i;
	int	cheap;
	int	cheap_i;

	i = 0;
	cheap = data->a.capacity;
	cheap_i = 0;
	while (i < data->a.len)
	{
		if (ft_abs(top_b - data->a.arr[i]) < cheap && (top_b - data->a.arr[i] < 0))
		{
			cheap = ft_abs(top_b - data->a.arr[i]);
			cheap_i = i;
		}
		if (cheap == 1)
			return (cheap_i);
		i++;
	}
	if (i == data->a.len && cheap_i == 0)
		cheap_i = 0;
	return (cheap_i);
}

int	desc_sort_count(int top_a, t_data *data, int count, int is_r) //TODO
{
	int	i;
	int	count2;
	int	cheap_b;

	i = 0;
	count2 = 0;
	cheap_b = data->b.arr[cheap_index_from_b(top_a, data)];
	while (data->b.arr[i] != cheap_b)
		i++;
	if (i <= data->b.len / 2)
	{
		count2 = i;
		if (is_r)
		{
			if (count2 < count)
				return (count + 0);
			else
				return (0 + count2);
		}
	}
	else
	{
		count2 = data->b.len - i;
		if (!is_r)
		{
			if (count2 < count)
				return (count + 0);
			else
				return (0 + count2);
		}
	}
	return (count + count2);
}
      

int	cheap_index_from_a_to_b(t_data *data) //TODO
{
	int	i;
	int	tmp;
	int	cheap_i;
	int	count;
	int	is_r;

	i = 0;
	is_r = 0;
	tmp = data->a.capacity;
	cheap_i = 0;
	while (i < data->a.len)
	{
		count = 0;
		is_r = 0;
		if (i <= data->a.len / 2)
		{
			count = i;
			is_r = 1;
		}
		else
			count = data->a.len - i;
		count = desc_sort_count(data->a.arr[i], data, count, is_r);
		if (count < tmp)
		{
			tmp = count;
			cheap_i = i;
		}
		i++;
	}
	return (cheap_i);
}
