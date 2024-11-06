/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:14:48 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 10:26:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printptr(va_list ap)
{
	char	*argp;
	int	argp_len;

	argp = va_arg(ap, char *);
	if (argp == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		ft_putstr_fd(argp, 1);
	argp_len = (int)ft_strlen((const char *)argp);
	return (argp_len);
}
