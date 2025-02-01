/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/01 13:21:36 by pamallet         ###   ########.fr       */
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

int	desc_sort_count(int top_a, t_stack *b)
{
	int	i;
	int	nb_op;
	int	cheap_elem;

	i = 0;
	nb_op = 0;
	cheap_elem = b->arr[cheap_index_from_b(top_a, b)];
	while (b->arr[i] != cheap_elem)
	{
		nb_op = 1;
		if (i <= b->len / 2)
			nb_op += i;
		else
			nb_op += b->len - i;
		i++;
	}
	return (nb_op);
}

int	cheap_index_from_a(t_data *data)
{
	int	i;
	int	save;
	int	save_i;
	int	count;

	i = 0;
	save = data->a.len; //max
	save_i = i;
	while (i < data->a.len)
	{
		count = 0;
		if (i <= data->a.len / 2)
			count += i;
		else
			count += data->a.len - i; //ra / rra counter: OK
		count += desc_sort_count(data->a.arr[i], &data->b);
		if (count < save)
		{
			save = count;
			save_i = i;
		}
		i++;
	}
	return (save_i);
}

void	desc_sort_b(int cheap_a, t_stack *b)
{
	int	cheap_b;
	int	cheap_index_b;

	cheap_index_b = cheap_index_from_b(cheap_a, b);
	cheap_b = b->arr[cheap_index_b];
	while (b->arr[0] != cheap_b)
	{
		if (cheap_index_b <= (b->len / 2))
			rotate(b);
		else
			rev_rotate(b);
	}
}

void	rotate_to_top_a(int cheap_index_a, t_stack *a)
{
	int	i;

	i = 0;
	while (a->arr[0] != a->arr[cheap_index_a])
	{
		if (cheap_index_a <= (a->len / 2))
			rotate(a);
		else
			rev_rotate(a);
	}
}

void	a_to_b_sort(t_data *data)
{
	int cheap_index_a;

	cheap_index_a = cheap_index_from_a(data);
	printf("i: %d\n", cheap_index_a);
	rotate_to_top_a(cheap_index_a, &data->a);
	desc_sort_b(data->a.arr[cheap_index_a], &data->b);
	push(&data->a, &data->b);
}

void	first_desc_sort_b(t_stack *stk)
{
	if (stk->arr[0] < stk->arr[1])
		swap(stk);
}

void	turk_sort(t_data *data)
{
	if (data->a.len > 3)
	{
		push(&data->a, &data->b);
		push(&data->a, &data->b);
		first_desc_sort_b(&data->b);
		while (data->a.len > 3)
			a_to_b_sort(data);
	}
	if (data->a.len == 3)
		three_sort(&data->a);
	//while (data->b.len > 0)
		//b_to_a_sort(data);
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
