/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/22 23:08:06 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->len)
		printf("%d ", stk->arr[i++]);
	printf("\n");
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
		init_stack(&data.a, av, 0);
		init_stack(&data.b, av, 1);
		/* swap_ops(&data, 0); */
		push_ops(&data, 1);
		push_ops(&data, 0);
		print_stack(&data.a);
		print_stack(&data.b);
	}
	return (0);
}
