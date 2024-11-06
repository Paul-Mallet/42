/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:01:31 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 17:25:31 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printhex(va_list ap, int c)
{
	int	argh;
	//int	argh_len;
	//char	*s;

	argh = va_arg(ap, int);
	if (c == 'x')
		ft_puthex_fd(argh, "0123456789abcdef", 1);
	else
		ft_puthex_fd(argh, "0123456789ABCDEF", 1);
	//s = (char *)ft_itohex(argh); //b10 -> b16! not == len
	//argh_len = (int)ft_strlen(s);
	//free(s);
	return (1);
}
