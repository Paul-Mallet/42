/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printb10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:13:54 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 22:51:35 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printb10(va_list ap)
{
	int	argi;
	int	argi_len;
	char	*s;

	argi = va_arg(ap, int);
	ft_putnbr_fd(argi, 1);
	s = (char *)ft_itoa(argi);
	argi_len = (int)ft_strlen(s);
	free(s);
	return (argi_len);
}
