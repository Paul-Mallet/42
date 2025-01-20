/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 00:33:42 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_digits(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (*s == '-')
			s++;
		while (is_digit(*s))
			s++;
		count++;
	}
	return (count);
}

void	init_stack(t_stack *stk, char **av)
{
	int	i;

	i = 0;
	while (av[++i])
		stk->len += count_digits(av[i]);
	stk->arr = (int *)malloc(stk->len * sizeof(int));
	if (!stk->arr)
		return (NULL);
	i = -1;
	while (++i < stk->len)
		stk->arr[i] = ft_atoi(av[i + 1]); //not working on "42 ...", TODO
}

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
	t_stack	stk;
	int	i;

	stk.arr = NULL;
	stk.len = 0;
	i = 0;
	if (ac > 1)
	{
		/* init */
		while (av[++i])
			is_valid_input(av[i]);
		init_stack(&stk, av);
		if (!arr)
			handle_error(ERROR_MSG);
		print_stack(&stk);
	}
	return (0);
}
