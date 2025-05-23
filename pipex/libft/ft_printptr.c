/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:14:48 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 12:13:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnull(int c)
{
	if (c == 's')
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, "(nil)", 5);
	return (5);
}

int	ft_printptr(va_list ap, int c)
{
	void			*argp;
	int				argp_len;
	char			*s;

	argp = va_arg(ap, void *);
	if (argp == NULL)
		return (ft_putnull(c));
	if (c == 's')
	{
		ft_putstr_fd((char *)argp, 1);
		argp_len = (int)ft_strlen((const char *)argp);
	}
	else
	{
		write(1, "0x", 2);
		ft_putaddrs_fd((unsigned long)argp, "0123456789abcdef", 1);
		s = (char *)ft_ultohex((unsigned long)argp);
		argp_len = ((int)ft_strlen(s) + 2);
		free(s);
	}
	return (argp_len);
}
