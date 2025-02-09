/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:21:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 17:23:39 by pamallet         ###   ########.fr       */
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
		ft_printf("p%c\n", to->name);
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
	ft_printf("s%c\n", stk->name);
}

void	rotate(t_stack *stk, t_data *data, int is_final)
{
	int		i;
	int		tmp;
	char	*str;

	i = -1;
	tmp = stk->arr[0];
	while (++i < stk->len - 1)
		stk->arr[i] = stk->arr[i + 1];
	if (i == stk->len - 1)
		stk->arr[i] = tmp;
	if (!is_final)
	{
		str = (char *)malloc((2 + 1) * sizeof(char));
		if (!str)
			handle_error(ERROR_MSG);
		str[0] = 'r';
		str[1] = stk->name;
		str[2] = '\0';
		data->log_ops[data->log_index] = str;
		data->log_index++;
	}
}

void	rev_rotate(t_stack *stk, t_data *data, int is_final)
{
	int		i;
	int		tmp;
	char	*str;

	i = stk->len;
	tmp = stk->arr[i - 1];
	while (--i > 0)
		stk->arr[i] = stk->arr[i - 1];
	if (i == 0)
		stk->arr[i] = tmp;
	if (!is_final)
	{
		str = (char *)malloc((3 + 1) * sizeof(char));
		if (!str)
			handle_error(ERROR_MSG);
		str[0] = 'r';
		str[1] = 'r';
		str[2] = stk->name;
		str[3] = '\0';
		data->log_ops[data->log_index] = str;
		data->log_index++;
	}
}
