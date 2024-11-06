/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:22:40 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/06 17:37:22 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_printb10(va_list ap);
unsigned int	ft_printub10(va_list ap);
int		ft_printchar(va_list ap, int c);
int		ft_printptr(va_list ap);
int		ft_printhex(va_list ap, int c);
char		*ft_uitoa(unsigned int n);
void		ft_putunbr_fd(unsigned int n, int fd);
void		ft_puthex_fd(int n, char *shex, int fd);

#endif
