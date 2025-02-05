/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:36:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/05 19:35:16 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	desc_rotate_len(int top_a, t_stack *b)
{
	int	i;
	int	count;
	int	cheap_b;

	i = 0;
	count = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //ok
	while (b->arr[i] != cheap_b) //ok
		i++;
	if (i <= b->len / 2) //rb
		count = i;
	else //rrb
		count = b->len - i;
	return (count);
}

/* int	asc_rotate_len(int top_b, t_stack *a) */
/* { */
/* 	int	i; */
/* 	int	count; */
/* 	int	cheap_b; */

/* 	i = 0; */
/* 	count = 0; */
/* 	cheap_a = a->arr[cheap_index_from_a(top_b, a)]; //ok //TODO */
/* 	while (a->arr[i] != cheap_a) //ok */
/* 		i++; */
/* 	if (i <= b->len / 2) //ra */
/* 		count = i; */
/* 	else //rra */
/* 		count = a->len - i; */
/* 	return (count); */
/* } */

int	desc_rotate_nb_ops(int top_a, t_stack *b, int count, int is_r)
{
	int	i;
	int	count2;
	int	cheap_b;

	i = 0;
	count2 = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //ok
	/* printf("cheap_b: %d\n", cheap_b); 7*/
	while (b->arr[i] != cheap_b) //ok
		i++;
	/* printf("[%d]\n", i); 7 at [1]*/
	if (i <= b->len / 2) //rb
	{
		count2 = i;
		/* printf("count(rb): %d && count2: %d && is_r: %d\n", count, count2, is_r); */
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
	/* printf("count: %d, count2: %d\n", count, count2); */
	return (count + count2);
}

int	asc_rotate_nb_ops(int top_a, t_stack *b) //TODO
{
	int	i;
	int	count;
	int	cheap_b;

	i = 0;
	count = 0;
	cheap_b = b->arr[cheap_index_from_b(top_a, b)]; //TODO ???
	while (b->arr[i] != cheap_b) //ok
		i++;
	if (i <= b->len / 2) //ra
		count = i;
	else //rra
		count = b->len - i;
	return (count);
}

