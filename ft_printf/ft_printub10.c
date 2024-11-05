/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printub10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:28:01 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/05 12:51:16 by pamallet         ###   ########.fr       */
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
	if (!argui)
		return (0);
	//ft_putunbr_fd(argui, 1);
	s = (const char *)ft_itoa(argui);
	argui_len = (unsigned int)ft_strlen(s);
	free(s);
	return (argui_len);
}
