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

static int	ft_is_specifier(const char c);
{
	const char	*s = "cspdiuxX%";

	while (*s)
	{
		if (*s == c)
			return (c); //cast to int
	}

	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;		//arg_list
	void		*arg;	//to cast
	char		c;
	int			cnt;

	va_start(ap, s);

	while (*s)
	{
		if (*s == '%' && ft_is_specifier(*s + 1)) //check '%d'
		{
			c = ft_is_specifier(*s + 1); //return 'd'(100 in b10) or 0
			if (c == 'd' || c == 'i')    //ft?
			{
				(int)arg = va_arg(ap, int);
				if (!arg)				 //necessary?
					return (-1);
				ft_putnbr_fd((int)arg, 1);
				//cnt = ft_
			}
			if (c == 'c' || c == '%')
			{
				(char)arg = va_arg(ap, char);
				if (!arg)
					return (-1);
				ft_putchar_fd((char)arg, 1);
			}
			//...
		}
		else if (*s != '%' && ft_isascii(*s))
			ft_putchar((int)*s);
		else
			return (-1); //errors
		s++;
	}

	va_end(ap);
	return (cnt); //counter
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		/* ft_printf("c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, %: %%\n", av[1], ft_atoi(av[1])); //char *, int */
		printf("c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, prct: %%, w: %3d\n", av[1][0], av[1], av[1]+1, ft_atoi(av[1]), ft_atoi(av[1]), ft_atoi(av[1]), 0x28, 0x28, ft_atoi(av[1]));
		printf("test de %", 42);
	}
	else
	{
		/* ft_printf("Invalid arguments!"); */
		printf("Invalid arguments!");
	}
	return(0);
}
