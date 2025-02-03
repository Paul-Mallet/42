/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:36:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/03 23:07:36 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	desc_rotate_count(int top_a, t_stack *b, int count, int is_r)
{
	int	i;
	int	count2;
	int	cheap_b;

	i = 0;
	count2 = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //ok
	while (b->arr[i] != cheap_b) //ok
		i++;
	if (i <= b->len / 2) //rb
	{
		count2 = i;
		if (is_r) //ra
		{
			if (count2 < count)
				return (count + 0);
			else
				return (0 + count2);
		}
	}
	else //rrb
	{
		count2 = b->len - i;
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
