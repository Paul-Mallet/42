/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/23 12:20:40 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_data *data)
{
	int	i;

	if (data->b.len)
	{
		data->a.len += 1;
		i = data->a.len;
		while (--i > 0)
			data->a.arr[i] = data->a.arr[i - 1];
		data->a.arr[0] = data->b.arr[0];
		i = -1;
		while (++i < data->b.len - 1)
			data->b.arr[i] = data->b.arr[i + 1];
		data->b.len -= 1;
	}
}

static void	push_b(t_data *data)
{
	int	i;

	if (data->a.len) //if 0, will not push(b is full capacity)
	{
		data->b.len += 1;
		i = data->b.len;
		while (--i > 0)
			data->b.arr[i] = data->b.arr[i - 1];
		data->b.arr[0] = data->a.arr[0];
		i = -1;
		while (++i < data->a.len - 1)
			data->a.arr[i] = data->a.arr[i + 1];
		data->a.len -= 1;
	}
}

void	push_ops(t_data *data, int option)
{
	char	c;

	c = 'a';
	if (option == 0)
	{
		push_a(data);
		c = 'a';
	}
	else
	{
		push_b(data);
		c = 'b';
	}
	printf("p%c\n", c);
}

static void	swap(t_stack stk)
{
	int	tmp;

	if (stk.len > 1)
	{
		tmp = stk.arr[0];
		stk.arr[0] = stk.arr[1];
		stk.arr[1] = tmp;
	}
}

void	swap_ops(t_data *data, int option)
{
	char	c;

	if (option == 0)
	{
		swap(data->a);
		c = 'a';
	}
	else if (option == 1)
	{
		swap(data->b);
		c = 'b';
	}
	else
	{
		swap(data->a);
		swap(data->b);
		c = 's';
	}
	printf("s%c\n", c);
}
