/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/14 17:07:17 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo philo = *(t_philo*)arg;
	// int min = philo->id;
	// int max = (philo->id + 1) % philo->data->num_philos;
	// int left_fork = min;
	// int right_fork = max;

	while (!arg->data->simulation_stop) //when 1 stop loop
	{
		/* THINK */
		printf("%s %d is thinking\n");
		// usleep(10); //just to avoid case when philo can't take forks
		/* TAKE 2 FORKS - lower 1rst / higher 2nd */
		// pthread_mutex_lock(&forks[left_fork]);
		// printf("%s %d has taken a fork\n", );
		// pthread_mutex_lock(&forks[right_fork]);
		// printf("%s %d has taken a fork\n", );

		/* EAT */
		printf("%s %d is eating: %s\n");
		// usleep(philo->data->tt_eat);
		//-> A message announcing a philosopher died should be displayed
		//   no more than "10 ms after" the actual death of the philosopher.

		/* DROP 2 FORKS */
		// pthread_mutex_unlock(&forks[right_fork]);	//release max 1rst to reduce contention
		// pthread_mutex_unlock(&forks[left_fork]);
		// no printf here

		/* SLEEP */
		printf("%s %d is sleeping: %s\n");
		// usleep(philo->data->tt_sleep);
	}
	return (NULL);
}

//dedicated monitor function runs in its own thread
//continuously checks all philos status(loop)
//check if time_elapsed since last_meal > tt_die for any philo
void *monitor_routine(void *arg)
{
	t_data *data = (t_data *)arg;
	
	while (!simulation_stop)
	{
		//loop num_philos
		//get_current_time()
	}
}

void	start_diner(t_data *data)
{
	int	i;
	//...

	/* LOOP MUTEXES INIT(0) */
	i = -1;
	while (data->forks[++i])
		pthread_mutex_init(&data->forks[i], NULL);

	/* LOOP THREADS CREATE(1) */
	i = -1;
	while (data->philos[++i])
		if (pthread_create(&data->philos->thread, NULL, &routine, &data) != 0)
			return (EXIT_FAILURE);
	i = -1;
	while (data->philos[++i])
		if (pthread_join(data->philos->thread, NULL) != 0)
			return (EXIT_FAILURE);
	/* ... */
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 5 && ac <= 6)
	{
		if (!parsing(av))
			return (EXIT_FAILURE);
		init_data(&data, av);
		if (!check_data(&data))
			return (EXIT_FAILURE);
		print_data(&data);
		start_diner(&data);
	}
	else
		printf("Invalid number of args.\n");
	return (EXIT_SUCCESS);
}
