/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:01:47 by paul_mall         #+#    #+#             */
/*   Updated: 2024/12/09 11:40:39 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_bufs(char *buf, char *tmp_buf)
{
	char	*tmp_line;

	tmp_line = ft_strjoin(buf, tmp_buf);
	free(buf);
	return (tmp_line);
}

char	*read_file(char *buf, int fd)
{
	char	*tmp_buf;
	int		size;

	if (!buf)
		buf = ft_calloc(1, 1);
	tmp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, tmp_buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(tmp_buf);
			return (NULL);
		}
		tmp_buf[size] = '\0';
		buf = concat_bufs(buf, tmp_buf);
		if (ft_strchr(tmp_buf, '\n'))
			break ;
	}
	free(tmp_buf);
	return (buf);
}

char	*extract_line(char *buf)
{
	char	*line;
	int		len;

	len = 0;
	if (!buf[len]) //?
		return (NULL);
	while (buf[len] && buf[len] != '\n')
		len++;
	line = (char *)malloc(((len + 1) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (buf[len] && buf[len] != '\n')
	{
		line[len] = buf[len];
		len++;
	}
	if (buf[len] && buf[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

char	*buffer_rest(char *buf)
{
	char	*next_buf;
	int		len;
	int		i;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (!buf[len])
	{
		free(buf);
		return (NULL);
	}
	next_buf = (char *)malloc(((ft_strlen(buf) - len) + 1) * sizeof(char));
	if (!next_buf)
		return (NULL);
	len++;
	i = 0;
	while (buf[len])
		next_buf[i++] = buf[len++];
	next_buf[i] = '\0';
	free(buf);
	return (next_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1) //?
		return (NULL);
	buf = read_file(buf, fd);
	if (!buf)
		return (NULL);
	line = extract_line(buf);
	buf = buffer_rest(buf);
	return (line);
}

/* int	main(int ac, char **av) */
/* { */
/* 	int		fd; */
/* 	char	*line; */

/* 	if (ac > 1) */
/* 		fd = open(av[1], O_RDONLY); */
/* 	else */
/* 		fd = 0; */
/* 	if (fd < 0) */
/* 		printf("File not opened!"); */
/* 	while (1) */
/* 	{ */
/* 		line = get_next_line(fd); */
/* 		if (!line) */
/* 		{ */
/* 			printf("(null)"); */
/* 			free(line); */
/* 			break ; */
/* 		} */
/* 		printf("%s", line); */
/* 		free(line); */
/* 		line = NULL; */
/* 	} */
/* 	if (close(fd) == 0) */
/* 		printf("Fd:%d closed successfully.", fd); */
/* 	return (0); */
/* } */
