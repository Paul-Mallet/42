/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:43:54 by pamallet          #+#    #+#             */
/*   Updated: 2024/11/29 16:43:49 by pamallet         ###   ########.fr       */
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
int	ft_strlen(char *str);
char	*ft_strdup(char *str);

#endif
