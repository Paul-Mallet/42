/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/03 22:56:00 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->len)
		ft_printf("%d ", stk->arr[i++]);
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_data	data;
	int	i;

	i = 0;
	if (ac > 1)
	{
		while (av[++i])
			is_valid_input(av[i]);
		init_stack(&data.a, av, 'a');
		init_stack(&data.b, av, 'b');
		init_stack(&data.cpy, av, 'c');
		fill_stack(&data.a, av);
		fill_stack(&data.cpy, av);
		bubble_sort(&data.cpy);
		refill_stack(&data.a, &data.cpy);
		turk_sort(&data);
		print_stack(&data.a);
		print_stack(&data.b);
		free_stacks(&data);
	}
	return (0);
}
