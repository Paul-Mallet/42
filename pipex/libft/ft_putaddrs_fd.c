/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddrs_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:11 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 17:54:13 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddrs_fd(unsigned long n, char *shex, int fd)
{
	if (n > 0 && n <= 15) //>= 0
		write(fd, &shex[n % 16], 1);
	else
	{
		ft_putaddrs_fd(n / 16, shex, fd);
		ft_putaddrs_fd(n % 16, shex, fd);
	}
}
