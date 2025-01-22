/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/22 18:54:11 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate, reverse rotate = circular buffer

void	push(t_data *data)
{
	if (data->a.arr) //from a to b(top == b.arr[0])
	{
		//loop
		printf("a len: %d, b len:%d\n", data->a.len, data->b.len);
	}
}

void	push_ops(t_data *data, int option)
{
	char	c;

	c = 'a';
	if (option == 1)
	{
		push(data);
		c = 'b';
	}
	printf("p%c\n", c);
}

void	swap(t_stack stk)
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
