/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 17:58:54 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_single_philo(t_data *data)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = &data->philos[i];

	//START LAST_MEAL_TIME
	philo->last_meal_time = data->start_time;

	/* CREATE MONITOR BEFORE PHILOS ROUTINES*/
	handle_thread(data, i, CREATE, true);

	// CREATE THREAD(SINGLE PHILO)
	handle_thread(data, i, CREATE, false);

	// JOIN THREAD(SINGLE PHILO)
	handle_thread(data, i, JOIN, false);

	/* JOIN MONITOR LAST */
	handle_thread(data, i, JOIN, true);
}

void	handle_multiple_philos(t_data *data)
{
	unsigned int	i;

	//BOOL to start routine when all_thread_ready?
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}
	//wrap in mutexes? when implement it?

	/* MONITOR CREATE */
	handle_thread(data, i, CREATE, true);

	/* PHILOS[i].THREADS CREATE(1) ROUTINES */
	//check all threads are running?
	i = 0;
	while (i < data->num_philos)
	{
		handle_thread(data, i, CREATE, false);
		i++;	
	}

	/* PHILOS[i].THREADS JOIN(2) ROUTINES */
	i = 0;
	while (i < data->num_philos)
	{
		handle_thread(data, i, JOIN, false);
		i++;
	}

	/* MONITOR JOIN */
	handle_thread(data, i, JOIN, true);
}

void	start_dinner(t_data *data)
{
	/* START SIMULATION TIME & PHILOS LAST_MEAL_TIME */
	data->start_time = get_current_time_in_ms();

	/* CHECK SPECIAL CASES */
	if (data->num_philos == 0 || data->must_eat_count == 0)
		return ; //back main
	else if (data->num_philos == 1)
		handle_single_philo(data);
	else
		handle_multiple_philos(data);
}

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
		// print_data(&data);

		/* DINNER */
		start_dinner(&data);

		/* CLEAN */
		clean_data(&data);
	}
	else
		error_exit("Invalid arguments.\n Ex: 5 410 200 200 [7]");
	return (EXIT_SUCCESS);
}
