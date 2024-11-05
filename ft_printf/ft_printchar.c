/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:43:42 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/05 13:52:38 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printchar(va_list ap)
{
	int	argch;

	argch = va_arg(ap, int);
	if (!argch)
		return (0);
	printf("%c\n", (char)argch);
	ft_putchar_fd((char)argch, 1);
	return (1);
}
