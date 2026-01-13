/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddrs_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:00:11 by pamallet          #+#    #+#             */
/*   Updated: 2026/01/13 22:18:24 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddrs_fd(unsigned long n, char *shex, int fd)
{
	if ((int)n >= 0 && n <= 15)
		write(fd, &shex[n % 16], 1);
	else
	{
		ft_putaddrs_fd(n / 16, shex, fd);
		ft_putaddrs_fd(n % 16, shex, fd);
	}
}
