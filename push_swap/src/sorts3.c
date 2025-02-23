/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:44:12 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/22 13:44:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_index_bigger_b(t_stack *b)
{
	int	i;
	int	bigger_saved;

	i = 0;
	bigger_saved = 0;
	while (i < b->len)
	{
		if (b->arr[i] > b->arr[bigger_saved])
			bigger_saved = i;
		i++;
	}
	return (bigger_saved);
}

void	last_desc_sort_b(t_data *data)
{
	int	index_bigger_b;
	int	bigger;

	index_bigger_b = get_index_bigger_b(&data->b);
	bigger = data->b.arr[index_bigger_b];
	while (data->b.arr[0] != bigger)
	{
		if (index_bigger_b <= (data->b.len / 2))
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
