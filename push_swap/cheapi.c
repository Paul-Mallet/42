/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:39:37 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/03 19:22:36 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheap_index_from_b(int top_a, t_stack *b) //a[0], b
{
	int	i;
	int	cheap;
	int	cheap_i;

	i = 0;
	cheap = top_a;
	cheap_i = 0;
	while (i < b->len)
	{
		if ((top_a - b->arr[i]) < cheap && (top_a - b->arr[i]) > 0) //max - shorter
		{
			cheap = top_a - b->arr[i];
			cheap_i = i;
		}
		if (cheap == 1)
			return (cheap_i);
		i++;
	}
	if (i == b->len && cheap_i == 0) //new min, above biggest(sorted bef!)
		cheap_i = 0;
	return (cheap_i);
}

int	cheap_index_from_a_to_b(t_data *data) //3 rows
{
	int	i;
	int	tmp;
	int	cheap_i;
	int	count;
	int	is_r;

	i = -1; //
	is_r = 0;
	tmp = data->a.len; //max
	cheap_i = i;
	while (++i < data->a.len)
	{
		count = 0;
		if (i <= data->a.len / 2)
		{
			count += i; //ra counter: OK, add bool r = true
			is_r = 1;
		}
		else
			count += data->a.len - i; //rra counter: OK
		count = desc_rotate_count(data->a.arr[i], &data->b, count, is_r); //+rb/rrb counter = total
		if (count < tmp)
		{
			tmp = count;
			cheap_i = i;
		}
	}
	return (cheap_i);
}
