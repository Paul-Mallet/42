/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:43:12 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/23 13:02:03 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack stk)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stk.arr[0];
	while (++i < stk.len - 1)
		stk.arr[i] = stk.arr[i + 1];
	if (i == stk.len - 1)
		stk.arr[i] = tmp;
}

void	rotate_ops(t_data *data, int option)
{
	char	c;

	if (option == 0)
	{
		rotate(data->a);
		c = 'a';
	}
	else if (option == 1)
	{
		rotate(data->b);
		c = 'b';
	}
	else
	{
		rotate(data->a);
		rotate(data->b);
		c = 'r';
	}
	printf("r%c\n", c);
}

static void	rev_rotate(t_stack stk)
{
	int	i;
	int	tmp;

	i = stk.len;
	tmp = stk.arr[i - 1];
	while (--i > 0)
		stk.arr[i] = stk.arr[i - 1];
	if (i == 0)
		stk.arr[i] = tmp;
}

void	rev_rotate_ops(t_data *data, int option)
{
	char	c;

	if (option == 0)
	{
		rev_rotate(data->a);
		c = 'a';
	}
	else if (option == 1)
	{
		rev_rotate(data->b);
		c = 'b';
	}
	else
	{
		rev_rotate(data->a);
		rev_rotate(data->b);
		c = 'r';
	}
	printf("rr%c\n", c);
}
