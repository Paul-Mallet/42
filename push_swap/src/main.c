/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/22 13:42:31 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->len)
		ft_printf("%d ", stk->arr[i++]);
	ft_printf("\n");
}

int	is_already_sort(t_stack *a)
{
	int	i;

	i = 0;
	while ((i < a->len - 1) && (a->arr[i] < a->arr[i + 1]))
		i++;
	if (i != a->len - 1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	i = 0;
	if (ac > 1)
	{
		while (av[++i])
			is_valid_input(av[i]);
		init_stack(&data.a, av, 'a');
		init_stack(&data.b, av, 'b');
		init_stack(&data.cpy, av, 'c');
		fill_stack(&data, &data.a, av);
		fill_stack(&data, &data.cpy, av);
		bubble_sort(&data.cpy);
		refill_stack(&data.a, &data.cpy);
		if (is_already_sort(&data.a))
		{
			free_stacks(&data);
			return (0);
		}
		turk_sort(&data);
		free_stacks(&data);
	}
	return (0);
}
