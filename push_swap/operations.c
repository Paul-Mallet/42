/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/01 23:02:49 by paul_mall        ###   ########.fr       */
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

void	rotate(t_stack *stk, char **log_ops, int log_index)
{
	int	i;
	int	tmp;
	char	*str;

	i = -1;
	tmp = stk->arr[0];
	while (++i < stk->len - 1)
		stk->arr[i] = stk->arr[i + 1];
	if (i == stk->len - 1)
		stk->arr[i] = tmp;
	str = (char *)malloc((2 + 1) * sizeof(char));
	if (!str)
		handle_error(ERROR_MSG);
	str[0] = 'r';
	str[1] = stk->name;
	str[2] = '\0';
	log_ops[log_index] = str;
	log_index++;
	printf("r%c\n", stk->name);
}

void	rev_rotate(t_stack *stk, char **log_ops, int log_index)
{
	int	i;
	int	tmp;
	char	*str;

	i = stk->len;
	tmp = stk->arr[i - 1];
	while (--i > 0)
		stk->arr[i] = stk->arr[i - 1];
	if (i == 0)
		stk->arr[i] = tmp;
	str = (char *)malloc((3 + 1) * sizeof(char));
	if (!str)
		handle_error(ERROR_MSG);
	str[0] = 'r';
	str[1] = 'r';
	str[2] = stk->name;
	str[3] = '\0';
	log_ops[log_index] = str;
	log_index++;
	printf("rr%c\n", stk->name);
}
