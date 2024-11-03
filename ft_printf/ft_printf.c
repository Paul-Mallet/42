/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:18:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/03 17:57:21 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft/libft.h"

/* static void	*ft_type(); */

/* int	ft_printf(const char *s, ...) */
/* { */
/* 	va_list		args; */
/* 	void		*cnt; */

/* 	va_start(args, s); */

/* 	while (cnt) */
/* 	{ */
/* 		cnt = va_arg(args, void *); */
/* 	} */

/* 	va_end(args); */
/* } */

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		/* ft_printf("c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, %: %%\n", av[1], ft_atoi(av[1])); //char *, int */
		printf("c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, prct: %%, w: %3d\n", av[1][0], av[1], av[1]+1, ft_atoi(av[1]), ft_atoi(av[1]), ft_atoi(av[1]), 0x28, 0x28, ft_atoi(av[1]));
	}
	else
	{
		/* ft_printf("Invalid arguments!"); */
		printf("Invalid arguments!");
	}
	return(0);
}
