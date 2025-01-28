/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/28 17:37:13 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int elem, t_stack *b)
{
	int	i;
	int	save;
	int	save_i;

	i = 1;
	save = elem - b->arr[0];
	save_i = i;
	while (i < b->len)
	{
		if ((elem - b->arr[i]) < save && (elem - b->arr[i]) > 0)
		{
			save = elem - b->arr[i];
			save_i = i;
		}
		if (save == 1)
			break ;
		i++;
	}
	return (save_i);
}

int	desc_sort_count(int elem, t_stack *b)
{
	int	i;
	int	nb_op;
	int	short_elem;

	i = 0;
	nb_op = 0;
	short_elem = b->arr[get_index(elem, b)]; //value
	while (b->arr[0] != short_elem) //short_elem not at top
	{
		if (get_index(elem, b) < (b->len / 2)) //ne pas effectuer les actions, compter!
			rotate(b);
		else
			rev_rotate(b);
		nb_op++;
	}
	return (nb_op);
}

void	cheap_sort(t_data *data)
{
	int	i;
	int	save;
	int	count;

	i = 0;
	save = 0;
	while (i < data->a.len)
	{
		count = 0;
		if (i == 0) //sort to top a
			count += desc_sort_count(data->a.arr[i], &data->b);
		/* if (count < save) */
		/* 	save = count; */
		printf("%d\n", count);
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
		/* while (data->a.len > 3) */
		cheap_sort(data); //counter
	}
	if (data->a.len == 3)
		three_sort(&data->a);
	//while (data->b.len > 0)
		//push_back to a
}

void	three_sort(t_stack *stk)
{
	printf("\n");
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
