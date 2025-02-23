/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:46:17 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/22 13:44:10 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first_desc_sort_b(t_stack *stk)
{
	if (stk->arr[0] < stk->arr[1])
		swap(stk);
}

void	two_sort(t_data *data)
{
	if (data->a.arr[0] > data->a.arr[1])
		swap(&data->a);
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

void	print_rotate_to_top_a(t_data *data, int cheap_i_a, int is_f_a_to_b)
{
	if (cheap_i_a <= (data->a.len / 2))
	{
		if (is_f_a_to_b)
			rotate(&data->a, data, 0);
		else
		{
			rotate(&data->a, data, 1);
			ft_printf("r%c\n", data->a.name);
		}
	}
	else
	{
		if (is_f_a_to_b)
			rev_rotate(&data->a, data, 0);
		else
		{
			rev_rotate(&data->a, data, 1);
			ft_printf("rr%c\n", data->a.name);
		}
	}
}
