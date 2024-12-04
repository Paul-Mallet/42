/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:54 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/04 15:31:06 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 13
#endif

char	*get_next_line(int fd);
int	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
