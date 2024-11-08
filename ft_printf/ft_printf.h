/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:22:40 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/08 12:06:16 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

unsigned int	ft_printub10(va_list ap);
int				ft_printf(const char *s, ...);
int				ft_printb10(va_list ap);
int				ft_printchar(va_list ap, int c);
int				ft_printptr(va_list ap, int c);
int				ft_printhex(va_list ap, int c);
void			ft_putunbr_fd(unsigned int n, int fd);
void			ft_puthex_fd(unsigned int n, char *shex, int fd);
void			ft_putaddrs_fd(unsigned long n, char *shex, int fd);
char			*ft_uitoa(unsigned int n);
char			*ft_uitohex(unsigned int n);
char			*ft_ultohex(unsigned long n);

#endif
