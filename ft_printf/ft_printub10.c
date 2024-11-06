/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printub10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:28:01 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 17:35:51 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned int	ft_printub10(va_list ap)
{
	unsigned int	argui;
	unsigned int	argui_len;
	char		*s;

	argui = va_arg(ap, unsigned int);
	ft_putunbr_fd(argui, 1);
	s = (char *)ft_uitoa(argui);
	argui_len = (unsigned int)ft_strlen((const char *)s);
	free(s);
	return (argui_len);
}
