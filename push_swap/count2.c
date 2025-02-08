/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:36:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/08 17:05:58 by pamallet         ###   ########.fr       */
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
	cheap_b = data->b.arr[cheap_index_from_b(top_a, data)]; //ok
	while (data->b.arr[i] != cheap_b) //ok
		i++;
	if (i <= data->b.len / 2) //rb
		count = i;
	else //rrb
		count = data->b.len - i;
	return (count);
}

int	desc_rotate_nb_ops(int top_a, t_data *data, int count, int is_r)
{
	int	i;
	int	count2;
	int	cheap_b;

	i = 0;
	count2 = 0;
	cheap_b = data->b.arr[cheap_index_from_b(top_a, data)]; //TODO
	/* ft_printf("count: %d\n", count); */
	while (data->b.arr[i] != cheap_b) //ok
		i++;
	if (i <= data->b.len / 2) //rb
	{
		count2 = i;
		if (is_r) //ra
		{
			if (count2 < count)
				return (count + 0); //TODO
			else
				return (0 + count2);
		}
	}
	else //rrb
	{
		count2 = data->b.len - i;
		if (!is_r) //rra
		{
			if (count2 < count)
				return (count + 0);
			else
				return (0 + count2);
		}
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
	while (data->a.arr[i] != cheap_a) //ok
		i++;
	if (i <= data->a.len / 2) //ra
		count = i;
	else //rra
		count = data->a.len - i;
	return (count);
}

