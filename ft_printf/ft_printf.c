/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:18:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/04 19:36:00 by pamallet         ###   ########.fr       */
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
		s++;
	}
	return (0);
}

static int	ft_printarg(va_list ap, int c)
{
	if (c == 'd' || c == 'i')
		return (ft_printb10(ap));
	/* else if (c == 's' || c == 'p') */
	/* 	return (ft_printptr(ap)); */
	/* else if (c == 'c' || c == '%') */
	/* 	return (ft_printchar(ap)); */
	/* else if (c == 'x' || c == 'X') */
	/* 	return (ft_printhex(ap); */
	/* else if (c == 'u') */
	/* 	return (ft_printub10(ap)); */
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int		c;
	int		argi;
	int		cnt;
	int		i;

	va_start(ap, s);
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_is_specifier(s[i + 1])) //check '%d'
		{
			c = ft_is_specifier(s[i + 1]);	//return 'd'(100 in b10) or 0
			if (ft_printarg(ap, c))
				return (-1);
			//see if it prints
			/* if (c == 'd' || c == 'i') */
			/* { */
			/* 	argi = va_arg(ap, int); */
			/* 	if (!argi) */
			/* 		return (-1); */
			/* 	ft_putnbr_fd(argi, 1); */
			/* 	cnt += ft_strlen((const char *)ft_itoa(argi)); */
			/* } */
			if (c == 'c' || c == '%')
			{
				argi = va_arg(ap, int);
				if (!argi)
					return (-1);
				ft_putchar_fd((char)argi, 1);
				cnt++;
			}
			i += 2;
		}
		if (s[i] != '%' && ft_isascii(s[i]))
		{
			ft_putchar_fd((int)s[i], 1);
			cnt++;
		}
		else
			return (-1);
		i++;
	}
	va_end(ap);
	return (cnt);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_printf len: %d\n", ft_printf("d: %d\n", 42));
		printf("printf len: %d\n", printf("d: %d\n", 42));
		//printf("c: %c, s: %s, p: %p, d: %d, i: %i, u: %u, x: %x, X: %X, prct: %%, w: %3d\n", av[1][0], av[1], av[1]+1, ft_atoi(av[1]), ft_atoi(av[1]), ft_atoi(av[1]), 0x28, 0x28, ft_atoi(av[1]));
	}
	else
	{
		/* ft_printf("Invalid arguments!"); */
		printf("Invalid arguments!");
	}
	return(0);
}
//handle '\0' as arg -> cnt=1, so x5 -> cnt=5!
