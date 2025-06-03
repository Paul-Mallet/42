/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:06:25 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 5 && ac <= 6)
	{
		/* PARSING */
		parsing(av);

		/* INIT DATA */
		init_data(&data, av);

		/* DEBUG */
		print_data(&data);

		/* DINNER */
		start_dinner(&data);

		/* CLEAN */
		clean_data(&data);
		//check_valgrind !
	}
	else
		error_exit("Invalid arguments.\n Ex: 5 410 200 200 [7]");
	return (EXIT_SUCCESS);
}
