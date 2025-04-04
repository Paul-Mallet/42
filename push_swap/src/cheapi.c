/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:39:37 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/22 13:43:17 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if ((top_a - data->b.arr[i]) < cheap
			&& (top_a - data->b.arr[i]) > 0)
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
		if (ft_abs(top_b - data->a.arr[i]) < cheap
			&& (top_b - data->a.arr[i] < 0))
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

int	desc_sort_count(int top_a, t_data *data, int count, int is_r)
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
			return (optimal_count(count, count2));
	}
	else
	{
		count2 = data->b.len - i;
		if (!is_r)
			return (optimal_count(count, count2));
	}
	return (count + count2);
}

int	cheap_index_from_a_to_b(t_data *data, int i)
{
	int	tmp;
	int	cheap_i;
	int	count;
	int	is_r;

	tmp = data->a.capacity;
	cheap_i = 0;
	while (++i < data->a.len)
	{
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
	}
	return (cheap_i);
}
