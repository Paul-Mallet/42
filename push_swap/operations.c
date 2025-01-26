/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/26 12:53:21 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	int	i;

	if (from->len > 0)
	{
		to->len += 1;
		i = to->len;
		while (--i > 0)
			to->arr[i] = to->arr[i - 1];
		to->arr[0] = from->arr[0];
		i = -1;
		while (++i < from->len - 1)
			from->arr[i] = from->arr[i + 1];
		from->len -= 1;
		printf("p%c\n", to->name);
	}
}

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->len > 1)
	{
		tmp = stk->arr[0];
		stk->arr[0] = stk->arr[1];
		stk->arr[1] = tmp;
	}
	printf("s%c\n", stk->name);
}

void	rotate(t_stack *stk)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = stk->arr[0];
	while (++i < stk->len - 1)
		stk->arr[i] = stk->arr[i + 1];
	if (i == stk->len - 1)
		stk->arr[i] = tmp;
	printf("r%c\n", stk->name);
}

void	rev_rotate(t_stack *stk)
{
	int	i;
	int	tmp;

	i = stk->len;
	tmp = stk->arr[i - 1];
	while (--i > 0)
		stk->arr[i] = stk->arr[i - 1];
	if (i == 0)
		stk->arr[i] = tmp;
	printf("rr%c\n", stk->name);
}
