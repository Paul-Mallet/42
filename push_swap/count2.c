/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:36:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/03 19:26:11 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	desc_rotate_count(int top_a, t_stack *b, int count, int is_r)
{
	int	i;
	int	nb_ops;
	int	cheap_b;

	i = 0;
	nb_ops = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //ok
	/* ft_printf("cheap_b: %d\n", cheap_b); */
	while (b->arr[i] != cheap_b) //ok
		i++;

	if (i <= b->len / 2) //rb
	{
		nb_ops = i;
		if (is_r) //ra
		{
			if (nb_ops < count)
				return (count + 0);
			else
				return (0 + nb_ops);
		}
	}
	else //rrb
	{
		nb_ops = b->len - i;
		if (!is_r) //rra
		{
			if (nb_ops < count)
				return (count + 0);
			else
				return (0 + nb_ops);
		}
		
	}
	/* ft_printf("nb_ops(b_sort): %d\n", nb_ops); //why 1? instead of 2 */
	return (count + nb_ops);
}
