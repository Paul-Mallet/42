/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/24 16:49:34 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(int a, int b)
{
	return (a < b);
}

/* void	least_ops(t_data *data) */
/* { */
/* 	if (ft_strcmp(data->order, "010")) */
/* 		swap_ops(data, 0); */
/* 	else if (ft_strcmp(data->order, "011")) */
/* 		rotate_ops(data, 0); */
/* 	else if (ft_strcmp(data->order, "101")) */
/* 		rev_rotate_ops(data, 0); */
/* 	else if (ft_strcmp(data->order, "100")) */
/* 	{ */
/* 		swap_ops(data, 0); */
/* 		rotate_ops(data, 0); */
/* 	} */
/* 	else if (ft_strcmp(data->order, "000")) */
/* 	{ */
/* 		swap_ops(data, 0); */
/* 		rev_rotate_ops(data, 0); */
/* 	} */
/* } */

//if data->a.len == 3, {2, 1, 3}
void	order_3_nums(t_stack *stk)
{
	/* int	i; */

	/* i = -1; */
	/* while (++i < stk->len - 1) */
	/* { */
	/* 	if ((*cmp)(stk->arr[i], stk->arr[i + 1])) */
	/* 		stk->order[i] = '1'; */
	/* } */
	/* if (i == stk->len - 1) */
	/* 	if ((*cmp)(stk->arr[0], stk->arr[stk->len - 1])) */
	/* 		stk->order[i] = '1'; */
	printf("%s\n", stk->order);
}
