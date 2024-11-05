/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:18:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/05 13:53:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	else if (c == 'c' || c == '%')
		return (ft_printchar(ap));
	/* else if (c == 'x' || c == 'X') */
	/* 	return (ft_printhex(ap); */
	/* else if (c == 'u') */
	/* 	return (ft_printub10(ap)); */
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int		arg_len;
	int		cnt;
	int		c;
	int		i;

	va_start(ap, s);
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_is_specifier(s[i + 1]))
		{
			c = ft_is_specifier(s[i + 1]);
			arg_len = ft_printarg(ap, c);
			if (!arg_len)
				return (-1);
			cnt += arg_len;
			i++;
		}
		else if (s[i] != '%' && ft_isascii(s[i]))
		{
			ft_putchar_fd((char)s[i], 1);
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
	(void)av;
	/* char	c = '%'; */
	if (ac == 2)
	{
		printf("ft_printf len: %d\n", ft_printf("d: %d, c: %c, %%\n", 42, 'A'));
		printf("printf len: %d\n", printf("d: %d, c: %c, %%\n", 42, 'A'));
		//write(1, &c, 1);
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
