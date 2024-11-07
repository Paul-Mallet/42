/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:18:36 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:23 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (c == 's' || c == 'p')
		return (ft_printptr(ap, c));
	else if (c == 'c' || c == '%')
		return (ft_printchar(ap, c));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(ap, c));
	else if (c == 'u')
		return (ft_printub10(ap));
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			cnt;
	int			i;

	va_start(ap, s);
	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_is_specifier(s[i + 1]))
		{
			cnt += ft_printarg(ap, ft_is_specifier(s[i + 1]));
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

/* int	main(int ac, char **av) */
/* { */
/* 	int	value = 0; */
/* 	int	*p; */

/* 	p = &value; */
/* 	printf("ft_printf len: %d\n", ft_printf("u: %u\n", 2000000000)); */
/* 	printf("printf len: %d\n", printf("p: %u\n", 2000000000)); */
/* 	return(0); */
/* } */
