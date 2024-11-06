/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:43:42 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 22:51:40 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(va_list ap, int c)
{
	int	argch;

	if (c == '%')
		ft_putchar_fd('%', 1);
	else
	{
		argch = va_arg(ap, int);
		ft_putchar_fd((char)argch, 1);
	}
	return (1);
}
