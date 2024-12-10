/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:01:47 by paul_mall         #+#    #+#             */
/*   Updated: 2024/12/10 13:41:38 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*concat_bufs(char *buf, char *tmp_buf)
{
	char	*tmp_line;

	if (!buf)
		buf = ft_calloc(1, 1);
	tmp_line = ft_strjoin(buf, tmp_buf);
	free(buf);
	return (tmp_line);
}

char	*read_file(char *buf, int fd)
{
	char	*tmp_buf;
	int		size;

	tmp_buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp_buf)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, tmp_buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
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
	if (!buf[len])
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
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	else
	{
		buf[fd] = read_file(buf[fd], fd);
		if (!buf[fd])
			return (NULL);
		line = extract_line(buf[fd]);
		buf[fd] = buffer_rest(buf[fd]);
	}
	return (line);
}

int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	int		i;
	char	*linefd1;
	char	*linefd2;

	(void)av;
	if (ac > 1)
	{
		fd1 = open("line.txt", O_RDONLY);
		fd2 = open("noline.txt", O_RDONLY);
	}
	else
	{
		fd1 = 0;
		(void)fd2;
	}
	while (1)
	{
		linefd1 = get_next_line(fd1);
		linefd2 = get_next_line(fd2);
		if (!linefd1 && !linefd2)
		{
			printf("(null)");
			free(line);
			break ;
		}
		printf("fd1: %s", linefd1);
		printf("fd2: %s", linefd2);
		free(linefd1);
		free(linefd2);
		linefd1 = NULL;
		linefd2 = NULL;
	}
	if (close(fd1) == 0 && close(fd2) == 0)
		printf("Fds closed successfully.", fd);
	return (0);
}
