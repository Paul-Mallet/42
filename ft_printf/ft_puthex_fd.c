/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:11 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/07 11:01:35 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(unsigned int n, char *shex, int fd)
{
	if (n >= 0 && n <= 15)
		write(fd, &shex[n % 16], 1);
	else
	{
		ft_puthex_fd(n / 16, shex, fd);
		ft_puthex_fd(n % 16, shex, fd);
	}
}
