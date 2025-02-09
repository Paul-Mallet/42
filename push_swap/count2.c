/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:36:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 17:48:40 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	desc_rotate_len(int top_a, t_data *data)
{
	int	i;
	int	count;
	int	cheap_b;

	i = 0;
	count = 0;
	cheap_b = data->b.arr[cheap_index_from_b(top_a, data)];
	while (data->b.arr[i] != cheap_b)
		i++;
	if (i <= data->b.len / 2)
		count = i;
	else
		count = data->b.len - i;
	return (count);
}

int	dsc_rot_nb_ops(int top_a, t_data *data, int count, int is_r)
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

int	asc_rotate_nb_ops(int top_b, t_data *data)
{
	int	i;
	int	count;
	int	cheap_a;

	i = 0;
	count = 0;
	cheap_a = data->a.arr[cheap_index_from_a(top_b, data)];
	while (data->a.arr[i] != cheap_a)
		i++;
	if (i <= data->a.len / 2)
		count = i;
	else
		count = data->a.len - i;
	return (count);
}
