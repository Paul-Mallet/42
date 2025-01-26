/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/26 13:44:55 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stk)
{
	if ((stk->len != 3)
		|| (stk->arr[0] < stk->arr[1] && stk->arr[1] < stk->arr[2]))
		return ;
	else if (stk->arr[0] > stk->arr[1] && stk->arr[1] < stk->arr[2])
		rotate(stk);
	else if (stk->arr[0] < stk->arr[1] && stk->arr[1] > stk->arr[2]
		&& stk->arr[0] > stk->arr[2])
		rev_rotate(stk);
	else if (stk->arr[0] > stk->arr[1] && stk->arr[1] < stk->arr[2]
		&& stk->arr[0] < stk->arr[2])
		swap(stk);
	else if (stk->arr[0] > stk->arr[1] && stk->arr[1] > stk->arr[2])
	{
		swap(stk);
		rev_rotate(stk);
	}
	else
	{
		swap(stk);
		rotate(stk);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	if ((a->len != 5) || (a->arr[0] < a->arr[1] && a->arr[1] < a->arr[2]
		&& a->arr[2] < a->arr[3] && a->arr[3] < a->arr[4]))
		return ;
	push(a, b);
	push(a, b);
	sort_three(a);
	if (b->arr[0] > b->arr[1])
	{
		swap(b);
		push(b, a);
		sort_by_insert(a);
		push(b, a);
		sort_by_insert(a);
	}
	else
	{
		push(b, a);
		sort_by_insert(a);
		push(b, a);
		sort_by_insert(a);
	}
}

void	sort_by_insert(t_stack *stk)
{
	//if len == 4 || len == 5
	//82, 1, 66, 833
	//implement turk sort for these 5
	//4e [0] -> [1], [2], [3](sorted, where insert it)
	if (a->arr[0] < a->arr[1])
		return ;
	else if (a->arr[0] > a->arr[1] && a->arr[0] < a->arr[2])
		swap(a);
	else if (a->arr[0] > a->arr[2] && a->arr[0] < a->arr[3])
	else if (a->arr[0] > a->arr[3] && a->len == 4)
		rotate(a);
}














