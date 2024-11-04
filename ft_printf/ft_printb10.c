/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printb10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:13:54 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/04 19:27:45 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft/libft.h"

int	ft_printb10(va_list ap)
{
	int	argi;

	if (c == 'd' || c == 'i')
	{
		argi = va_arg(ap, int);
		if (!argi)
			return (0);
		ft_putnbr_fd(argi, 1);
		return ((int)ft_strlen((const char *)ft_itoa(argi))); //free itoa?
	}
}
