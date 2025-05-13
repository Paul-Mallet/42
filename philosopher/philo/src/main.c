/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/08 16:13:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_philo philo = *(t_philo*)arg;
	//int left_fork;
	//int right_fork;

	while (1)
	{
		/* THINK */
		printf("%s %d is thinking\n");

		/* TAKE 2 FORKS - lower 1rst / higher 2nd */
		// pthread_mutex_lock(&forks[left_fork]);
		// printf("%s %d has taken a fork\n", );
		// pthread_mutex_lock(&forks[right_fork]);
		// printf("%s %d has taken a fork\n", );

		/* EAT */
		printf("%s %d is eating: %s\n");
		//check if dead

		/* DROP 2 FORKS */
		// pthread_mutex_unlock(&forks[left_fork]);
		// pthread_mutex_unlock(&forks[right_fork]);

		/* SLEEP */
		printf("%s %d is sleeping: %s\n");
		//check if dead
	}
	return (NULL);
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
