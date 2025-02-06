/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:39:37 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/06 11:45:24 by pamallet         ###   ########.fr       */
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
		if ((top_a - b->arr[i]) < cheap && (top_a - b->arr[i]) > 0)
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

int	cheap_index_from_a(int top_b, t_stack *a) //from_b_to_a cheap index OK
{
	int	i;
	int	cheap;
	int	cheap_i;

	i = 0;
	cheap = top_b;
	cheap_i = 0;
	while (i < a->len)
	{
		if (ft_abs(top_b - a->arr[i]) < cheap && (top_b - a->arr[i] < 0))
		{
			cheap = ft_abs(top_b - a->arr[i]);
			cheap_i = i;
		}
		if (cheap == 1)
			return (cheap_i);
		i++;
	}
	if (i == a->len && cheap_i == 0) //new max, above min, just rotate
		cheap_i = 0;
	return (cheap_i);
}

int	desc_sort_count(int top_a, t_stack *b, int count, int is_r)
{
	int	i;
	int	count2;
	int	cheap_b;

	i = 0;
	count2 = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)];
	while (b->arr[i] != cheap_b)
		i++;
	if (i <= b->len / 2) //rb
	{
		count2 = i;
		if (is_r) //ra
		{
			if (count2 < count)
				return (count + 0);
			else
				return (0 + count);
		}
	}
	else //rrb
	{
		count2 = b->len - i;
		if (!is_r) //rra
		{
			printf("rrr?\n");
			if (count2 < count)
				return (count + 0);
			else
				return (0 + count);
		}
	}
	return (count + count2);
}
      

int	cheap_index_from_a_to_b(t_data *data) //3 rows
{
	int	i;
	int	tmp;
	int	cheap_i;
	int	count;
	int	is_r;

	i = 0;
	is_r = 0;
	tmp = data->a.len; //max
	cheap_i = 0;
	while (i < data->a.len)
	{
		count = 0;
		is_r = 0;
		if (i <= data->a.len / 2)
		{
			count += i; //ra counter: OK, add bool r = true
			is_r = 1;
		}
		else
			count += data->a.len - i; //rra counter: OK
		count = desc_sort_count(data->a.arr[i], &data->b, count, is_r); //+rb/rrb counter = total
		if (count < tmp)
		{
			tmp = count;
			cheap_i = i;
		}
		i++;
	}
	return (cheap_i);
}
