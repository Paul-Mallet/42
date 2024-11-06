/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:47:09 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 16:59:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_nbrlen(int n)
{
	int	n_len;

	n_len = 1;
	while (n > 9)
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itohex(int n)
{
	//
}
