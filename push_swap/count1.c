/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:26:00 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/03 19:41:40 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_from_a_to_b(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = data->a.len; //max
	while (i < data->a.len)
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
	/* ft_printf("nb_ops: %d\n", data->nb_ops); */
}

static void	count_a_three_sort(t_data *data)
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
	/* 	count_from_b_to_a(data); //TODO*/
}
