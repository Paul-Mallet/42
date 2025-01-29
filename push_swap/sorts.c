/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/29 22:58:32 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	short_index(int elem, t_stack *stk)
{
	int	i;
	int	save;
	int	save_i;

	i = 0;
	save = elem - stk->arr[0];
	save_i = i;
	while (i < stk->len)
	{
		if ((elem - stk->arr[i]) < save && (elem - stk->arr[i]) > 0)
		{
			save = elem - stk->arr[i];
			save_i = i;
		}
		if (save == 1)
			break ;
		i++;
	}
	if (i == stk->len)
		save_i = 0;
	return (save_i);
}

int	desc_sort_count(int elem, t_stack *stk)
{
	int	nb_op;
	int	short_elem;

	nb_op = 0;
	short_elem = stk->arr[short_index(elem, stk)];
	while (stk->arr[0] != short_elem)
		nb_op++;
	return (nb_op);
}

int	cheapest_index(t_data *data)
{
	int	i;
	int	save;
	int	save_i;
	int	count;

	i = 0;
	save = data->a.len;
	save_i = i;
	while (i < data->a.len)
	{
		count = 0;
		if (i <= data->a.len / 2)
			count += i;
		else
			count += (i - data->a.len / 2);
		count += desc_sort_count(data->a.arr[i], &data->b); //stk b
		if (count < save)
		{
			save = count;
			save_i = i;
		}
		/* printf("%d\n", count); */
		i++;
	}
	return (save_i);
}

void	desc_sort(int cheapest_index, t_stack *stk) //*stk = b
{
	int	cheapest_elem;

	cheapest_elem = stk->arr[cheapest_index];
	while (stk->arr[0] != cheapest_elem)
	{
		if (cheapest_index < (stk->len / 2))
			rotate(stk);
		else
			rev_rotate(stk);
	}
}

//cheapest index(a), desc_sort(b), push(a->b)
//continue... until a->len = 3
void	a_to_b_sort(t_data *data)
{
	int i;

	i = cheapest_index(data);
	desc_sort(i, &data->b);
	push(&data->a, &data->b);
}

void	turk_sort(t_data *data)
{
	if (data->a.len > 3)
	{
		push(&data->a, &data->b);
		push(&data->a, &data->b);
		while (data->a.len > 3)
			a_to_b_sort(data);
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
