/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/02 18:53:15 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(void *arg)
{
	t_data data = *(t_data)arg;

	while (1)
	{
		/* THINK */
		printf("thinking: %s\n");

		/* TAKE 1 FORK */
		//lock
		/* TAKE 2nd FORK */
		//unlock

		/* EAT */
		printf("eating: %s\n");
		//check if dead

		/* DROP 2 FORKS */

		/* SLEEP */
		printf("sleeping: %s\n");
		//check if dead
	}
}

void	start_diner(t_data *data)
{
	int	i;
	//...

	/* LOOP THREADS(0) */
	i = -1;
	while (data->philos[++i])
		if (pthread_create(&data->philos->thread, NULL, &routine, &data) != 0)
			return (EXIT_FAILURE);
	i = -1;
	while (data->philos[++i])
		if (pthread_join(data->philos->thread, NULL) != 0)
			return (EXIT_FAILURE);

	/* LOOP MUTEXES(1) */
	// i = -1;
	// while (data->forks[++i])
	// 	pthread_mutex_init(&data->forks[i], NULL);
	// i = -1;
	// while (data->forks[++i])
	// 	pthread_mutex_lock(&data->forks[i]);
	// i = -1;
	// while (data->forks[++i])
	// 	pthread_mutex_unlock(&data->forks[i]);
	// i = -1;
	// while (data->forks[++i])
	// 	pthread_mutex_destroy(&data->forks[i]);
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

// pthread_t		t1, t2;

//fill 8 chars starting from str[13] with '.'
//memset("A string with many chars."[13], '.', 8 * sizeof(char));

//* quantum time reached, OS interrupt it to let another one exec


// void	*routine2()
// {
// 	sleep(3);  
// 	printf("Ending thread");
// }

// (1)
// pthread_mutex_init(&mutex, NULL) + pthread_mutex_destroy(&mutex)
// pthread_mutex_lock(&mutex) + pthread_mutex_unlock(&mutex)

// //CREATE = start exec in calling process, by exec routine()
// if (pthread_create(&t1, NULL, &routine, NULL) != 0)
// 	return (EXIT_FAILURE);
// pthread_create(&t2, NULL, &routine, NULL);

// //JOIN = wait for the ending of the target thread
// if (pthread_join(t1, NULL) != 0)
// 	return (EXIT_FAILURE);
// pthread_join(t2, NULL);


// //suspend thread exec
// //actual suspension time may be longer than the amount of time spe
// //(cause other activity / time to spent process call)
// unsigned int	usecs;

// usecs = 1500;
// usleep(usecs); //0(success) or -1(error)

// //for timestamp_in_ms, give n of microsec tv.tv_usec since Epoch(time)
// //if either tv or tz = NULL
// // struct timeval	*tv;
// // struct timezone	*tz; //?

// // gettimeofday(tv, tz);


// int	init_philos(t_data *data, char **av)
// {
// 	int	i;

// 	pthread_mutex_init(&data->mutex, NULL);
// 	i = -1;
// 	pthread_create(data->monitor, NULL, &monitor, NULL);
// 	while (++i < ft_atoi(av[1]))
// 	{
// 		if (pthread_create(data->philos[i].thread, NULL, &routine, NULL) != 0)
// 		{
// 			printf("Failed to create thread.\n");
// 			return (EXIT_FAILURE);
// 		}
// 	}
// 	i = -1;
// 	pthread_join(data->monitor, NULL);
// 	while (++i < ft_atoi(av[1]))
// 	{
// 		if (pthread_join(data->philos[i].thread, NULL) != 0)
// 		{
// 			printf("Failed to join thread.\n");
// 			return (EXIT_FAILURE);
// 		}
// 	}
// 	pthread_mutex_destroy(&data->mutex);
// 	return (EXIT_SUCCESS);
// }
