/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:01:31 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 00:21:41 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(va_list ap, int c)
{
	long	argh;
	int		argh_len;
	char	*s;

	argh = va_arg(ap, long);
	if (c == 'x')
		ft_puthex_fd(argh, "0123456789abcdef", 1);
	else
		ft_puthex_fd(argh, "0123456789ABCDEF", 1);
	s = (char *)ft_ltohex(argh);
	argh_len = (int)ft_strlen(s);
	free(s);
	return (argh_len);
}
