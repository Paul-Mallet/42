/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:36:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/03 13:37:29 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	desc_sort_count(int top_a, t_stack *b)
{
	int	i;
	int	nb_ops;
	int	cheap_b;

	i = 0;
	nb_ops = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //ok
	/* printf("cheap_b: %d\n", cheap_b); */
	while (b->arr[i] != cheap_b) //ok
		i++;
	if (i <= b->len / 2)
		nb_ops = i;
	else
		nb_ops = b->len - i;
	/* printf("nb_ops(b_sort): %d\n", nb_ops); //why 1? instead of 2 */
	return (nb_ops);
}
