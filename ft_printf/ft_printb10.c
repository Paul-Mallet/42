/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printb10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:13:54 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 12:19:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printb10(va_list ap)
{
	char	*s;
	int		argi;
	int		argi_len;

	argi = va_arg(ap, int);
	ft_putnbr_fd(argi, 1);
	s = (char *)ft_itoa(argi);
	argi_len = (int)ft_strlen(s);
	free(s);
	return (argi_len);
}
