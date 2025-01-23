/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:57 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//3 random numbers
//(*cmp)(int, int) //asc order
int	cmp(int a, int b)
{
	return (a < b); //0 or 1
}

//if stk->len == 3
void	3_rand_num(t_stack *stk)
{
	//[0] > [1] = 0, [1] < [2] = 1 | [0] < [2](asc order) = 0
	//"011", case 1
	int	i;
	char	str[3];

	i = -1;
	str = "000";
	while (++i < stk->len - 1)
	{
		if ((*cmp)(stk->arr[i], arr[i + 1])) // == 1
			str[i] == '1';
	}
	if (i == stk->len - 1)
		if ((*cmp)(stk->arr[0], stk->arr[stk->len - 1]))
			str[i] == '1';
	//"000", "001", "010", "100", "011", "110", "101", "111"
}
