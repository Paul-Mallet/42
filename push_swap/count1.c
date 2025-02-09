/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:26:00 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 12:58:57 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	len_log_ops_from_a_to_b(t_data *data, int cheap_i_from_a)
{
	data->len_log = 0;
	if (cheap_i_from_a <= data->a.len / 2)
		data->len_log = cheap_i_from_a;
	else
		data->len_log = data->a.len - cheap_i_from_a;
	data->len_log += desc_rotate_len(data->a.arr[cheap_i_from_a], data);
}

static void	count_from_a_to_b(t_data *data) //TODO
{
	int	i;
	int	tmp;
	int	tmp_i;
	int	is_r;

	i = -1;
	is_r = 0;
	tmp_i = 0;
	tmp = data->a.capacity;
	while (++i < data->a.len)
	{
		data->nb_ops = 0;
		is_r = 0;
		if (i <= data->a.len / 2)
		{
			data->nb_ops = i;
			is_r = 1;
		}
		else
			data->nb_ops = data->a.len - i;
		data->nb_ops = desc_rotate_nb_ops(data->a.arr[i], data, data->nb_ops, is_r);
		if (data->nb_ops < tmp)
		{
			tmp = data->nb_ops;
			tmp_i = i;
		}
	}
	data->nb_ops = tmp;
	len_log_ops_from_a_to_b(data, tmp_i);
}

static void	count_a_three_sort(t_data *data)
{
	if ((data->a.len != 3)
		|| (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] < data->a.arr[2]))
		data->len_log = 0;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2])
		data->len_log = 1;
	else if (data->a.arr[0] < data->a.arr[1] && data->a.arr[1] > data->a.arr[2]
		&& data->a.arr[0] > data->a.arr[2])
		data->len_log = 1;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] < data->a.arr[2]
		&& data->a.arr[0] < data->a.arr[2])
		data->len_log = 1;
	else if (data->a.arr[0] > data->a.arr[1] && data->a.arr[1] > data->a.arr[2])
		data->len_log = 2;
	else
		data->len_log = 2;
}

static void	count_from_b_to_a(t_data *data)
{
	data->nb_ops = asc_rotate_nb_ops(data->b.arr[0], data);
}

void	count_cheap_total_ops(t_data *data, int is_first, int is_second)
{
	if (data->a.len > 3 && is_first && !is_second)
		count_from_a_to_b(data);
	else if (data->a.len == 3 && !is_first && !is_second)
		count_a_three_sort(data);
	else
	  	count_from_b_to_a(data);
}
