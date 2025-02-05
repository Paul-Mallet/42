/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:26:00 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/05 23:36:23 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	len_log_ops_from_a_to_b(t_data *data)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = data->a.len; //max
	while (++i < data->a.len)
	{
		data->len_log = 0;
		if (i <= data->a.len / 2) //ra
			data->len_log += i;
		else
			data->len_log += data->a.len - i; //rra
		data->len_log += desc_rotate_len(data->a.arr[i], &data->b);
		if (data->len_log < tmp)
			tmp = data->len_log;
	}
	data->len_log = tmp; //= 2, log_index = 2 (with 8) if (rra, rrb) => rrr
}

static void	count_from_a_to_b(t_data *data)
{
	int	i;
	int	tmp;
	int	is_r;

	i = -1;
	is_r = 0;
	tmp = data->a.len; //max
	while (++i < data->a.len)
	{
		data->nb_ops = 0;
		is_r = 0;
		if (i <= data->a.len / 2) //ra
		{
			data->nb_ops += i;
			is_r = 1;
		}
		else
			data->nb_ops += data->a.len - i; //rra
		data->nb_ops = desc_rotate_nb_ops(data->a.arr[i], &data->b, data->nb_ops, is_r);
		if (data->nb_ops < tmp)
			tmp = data->nb_ops;
	}
	data->nb_ops = tmp; //nb_ops(rrr)
	len_log_ops_from_a_to_b(data); //len_log_ops(rra, rrb)
}

static void	count_a_three_sort(t_data *data) //need len_log_ops?
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

static void	count_from_b_to_a(t_data *data) //TODO count for cheap nb_ops
{
	data->nb_ops = asc_rotate_nb_ops(data->b.arr[0], &data->a); //TODO
}

void	count_cheap_total_ops(t_data *data, int is_first, int is_second)
{
	if (data->a.len > 3 && is_first && !is_second)
		count_from_a_to_b(data);
	else if (data->a.len == 3 && !is_first && !is_second)
		count_a_three_sort(data);
	else
	  	count_from_b_to_a(data);//TODO (0)
}
