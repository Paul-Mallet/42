/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:47:43 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 5 && ac <= 6)
	{
		parsing(av);
		init_data(&data, av);
		print_data(&data);
		start_dinner(&data);
		clean_data(&data);
		//check_valgrind !
	}
	else
		error_exit("Invalid arguments.\n Ex: 5 410 200 200 [7]");
	return (EXIT_SUCCESS);
}
