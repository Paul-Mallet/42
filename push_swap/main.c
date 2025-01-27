/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/27 12:07:54 by paul_mall        ###   ########.fr       */
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
		init_stack(&data.a, av, 'a');
		init_stack(&data.b, av, 'b');
		if (data.a.len == 3)
			sort_three(&data.a);
		print_stack(&data.a);
		print_stack(&data.b);
	}
	return (0);
}
