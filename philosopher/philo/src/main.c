/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 11:10:53 by pamallet         ###   ########.fr       */
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

	/* MONITOR BEFORE PHILOS ROUTINES*/
	if (pthread_create(&data->monitor, NULL, &monitor_routine, &data) != 0)
		return (EXIT_FAILURE);

	//CREATE THREAD(SINGLE PHILO)
	handle_thread(data, i, CREATE);

	//JOIN THREAD(SINGLE PHILO)
	handle_thread(data, i, JOIN);

	/* JOIN MONITOR LAST */
	if (pthread_join(data->monitor, NULL) != 0)
		return (EXIT_FAILURE);
}

void	handle_multiple_philos(t_data *data)
{
	int			i;

	//BOOL to start routine when all_thread_ready?
	i = -1;
	while (++i < data->num_philos)
		data->philos[i].last_meal_time = data->start_time;
	//wrap in mutexes? not already in loops
	//not get_current_time_in_ms(); -> each have same timestamp to start at same time

	//handle_thread, add monitor condition?
	/* MONITOR BEFORE PHILOS ROUTINES*/
	if (pthread_create(&data->monitor, NULL, &monitor_routine, &data) != 0)
		return (EXIT_FAILURE);

	/* LOOP THREADS CREATE(1) ROUTINES */
	i = -1;
	while (++i < data->num_philos)
		handle_thread(data, i, CREATE);

	/* LOOP THREADS JOIN(2) ROUTINES */
	i = -1;
	while (++i < data->num_philos)
		handle_thread(data, i, JOIN);
	
	/* JOIN MONITOR LAST */
	if (pthread_join(data->monitor, NULL) != 0)
		return (EXIT_FAILURE);
}

void	start_dinner(t_data *data)
{
	/* START SIMULATION TIME & PHILOS LAST_MEAL_TIME */
	data->start_time = get_current_time_in_ms();

	/* CHECK SPECIAL CASES */
	if (data->must_eat_count == 0) // && argc == 6 | 0 != NULL, means explicitly add it
		return ; //back main + clean
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
		//clean_data(&data);
	}
	else
		error_exit("Invalid arguments.\n Ex: 5 410 200 200 [7]");
	return (EXIT_SUCCESS);
}
