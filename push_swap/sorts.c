/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/27 19:20:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//based on elem a, desc_sort b
//top elem in b must be shortest to elem a
int	desc_sort(int elem, t_stack *b)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->b.arr[i]) //b.arr[0] < elem, but 
	{
		//
		//rb or rrb
		//bubble sort as indexes? better to sort?
		count++;
		i++;
	}
}

void	cheap_sort(t_data *data)
{
	int	i;
	int	save;
	int	count;

	i = 0;
	save = 0;
	while (data->a.arr[i]) //loop to push only 1 elem
	{
		count = 0;
		if (i == 0)
			count = desc_sort(data->a.arr[i], &data->b); //7, stack b
		else if (i < data->a.len / 2)
			//rotate
		else
			//rev_rotate
		if (i == 0 || count < save)
			save = count;
		i++;
	}
	//reuse only 1 iteration to apply save on elem
}

void	turk_sort(t_data *data) //a, b stacks
{
	if (data->a.len > 3) //len-- each time push to b
	{
		push(&data->a, &data->b);
		push(&data->a, &data->b);
		while (data->a.len > 3)
			cheap_sort(data); //counter
	}
	if (data->a.len == 3)
		three_sort(&data->a);
}

void	three_sort(t_stack *stk)
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
