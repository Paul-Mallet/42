/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printub10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:28:01 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/04 19:31:11 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include "libft/libft.h"

unsigned int	ft_printub10(va_list ap)
{
	unsigned int	argui;

	if (c == 'u')
	{
		argui = va_arg(ap, unsigned int);
		if (!argui)
			return (0);
		ft_putunbr_fd(argui, 1);
		return ((unsigned int)ft_strlen((const char *)ft_itoa(argui)));
	}
}
