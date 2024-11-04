/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:18:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/04 15:24:24 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft/libft.h"

static int	ft_is_specifier(const char c)
{
	const char	*s = "cspdiuxX%";

	while (*s)
	{
		if (*s == c)
			return (c);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int		ch;
	int		cnt;

	va_start(ap, s);
	cnt = 0;
	while (*s)
	{
		if (*s == '%' && ft_is_specifier(*s + 1)) //check '%d'
		{
			ch = ft_is_specifier(*s + 1);	//return 'd'(100 in b10) or 0
			if (ch == 'd' || ch == 'i')
			{
				if (!va_arg(ap, int))
					return (-1);
				ft_putnbr_fd(va_arg(ap, int), 1);
				cnt += ft_strlen((const char *)ft_itoa(va_arg(ap, int)));
				printf("cnt: %d\n", cnt);
			}
			if (ch == 'c' || ch == '%')
			{
				if (!va_arg(ap, int))
					return (-1);
				ft_putchar_fd((char)va_arg(ap, int), 1);
				cnt++;
			}
			s++;
		}
		else if (*s != '%' && ft_isascii(*s))
			ft_putchar_fd((int)*s, 1);
		else
			return (-1); //errors
		s++;
	}
	va_end(ap);
	return (cnt);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_printf("%c\n", av[1][0]);
		printf("ft_printf len: %d\n", ft_printf("%c\n", av[1][0]));
		//printf("c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, prct: %%, w: %3d\n", av[1][0], av[1], av[1]+1, ft_atoi(av[1]), ft_atoi(av[1]), ft_atoi(av[1]), 0x28, 0x28, ft_atoi(av[1]));
		//printf("test de %", 42);
	}
	else
	{
		/* ft_printf("Invalid arguments!"); */
		printf("Invalid arguments!");
	}
	return(0);
}
//handle '\0' as arg -> cnt=1, so x5 -> cnt=5!
