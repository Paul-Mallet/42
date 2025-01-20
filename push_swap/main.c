/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/20 19:12:59 by pamallet         ###   ########.fr       */
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

/* int	*ft_split(const char *s) */
/* { */
/* 	int	*arr; */
/* 	int	arr_len; */

/* 	arr_len = count_digits(s); */
/* 	arr = (int *)malloc(arr_len * sizeof(int)); */
/* 	if (!arr) */
/* 		return (NULL); */
/* 	//simple atoi() */
/* } */

int	main(int ac, char **av)
{
	int	*arr;

	arr = NULL;
	if (ac > 1)// && is_valid_input(av[1])) -> handle: "", multiple signs, 1 !digit
	{
		is_valid_input(av[1]);

		//arr = split(av[1]);
		printf("%d\n", count_digits(av[1]));
		if (!arr)
			handle_error(ERROR_MSG);
	}
	return (0);
}
