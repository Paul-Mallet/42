/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:36:32 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/14 14:44:53 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main( int ac, char **av )
{
	if (ac != 2) {
		printf("Too few arguments\nEx: ./get_next_line \"path_to_your_file.txt_to_read\"\n");
		return (1);
	}

	int fd;
	char* line = NULL;

	fd = open(av[1], O_RDONLY);
	if (fd < 0) {
		printf("Failed to open the file, check it exists and have the correct permissions\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
        free(line);
	}
	close(fd);
	return (0);
}