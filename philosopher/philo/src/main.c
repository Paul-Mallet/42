/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/20 18:58:18 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long long	get_current_time_in_ms()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;
	long long	curr_time;

	philo = (t_philo*)arg;
	left_fork = philo->id;
	right_fork = (philo->id + 1) % philo->data->num_philos;
	while (!philo->data->simulation_stop) //wrap in mutex(read)
	{
		/* THINK */
		curr_time = get_current_time_in_ms(); //before each actions, take care?
		printf("%lld %d is thinking\n", curr_time - philo->data->start_time, philo->id);
		usleep(10); //just to avoid case when philo can't take forks
		
		/* TAKE 2 FORKS - lower 1rst / higher 2nd */
		pthread_mutex_lock(&philo->data->forks[left_fork]);
		curr_time = get_current_time_in_ms(); //before each actions?
		printf("%lld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->data->forks[right_fork]);
		curr_time = get_current_time_in_ms(); //before each actions?
		printf("%lld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);

		/* EAT */
		curr_time = get_current_time_in_ms(); //before each actions?
		printf("%lld %d is eating\n", curr_time - philo->data->start_time, philo->id);
		usleep(philo->data->tt_eat);

		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->last_meal_time = get_current_time_in_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		//-> A message announcing a philosopher died should be displayed
		//   no more than "10 ms after" the actual death of the philosopher.

		/* DROP 2 FORKS */
		pthread_mutex_unlock(&philo->data->forks[right_fork]);	//release max 1rst to reduce contention
		pthread_mutex_unlock(&philo->data->forks[left_fork]);
		// no printf here

		/* SLEEP */
		curr_time = get_current_time_in_ms(); //before each actions?
		printf("%lld %d is sleeping\n", curr_time - philo->data->start_time, philo->id);
		usleep(philo->data->tt_sleep);
	}
	return (NULL);
}

//dedicated monitor function runs in its own thread
//continuously checks all philos status(loop)
//check if time_elapsed since last_meal > tt_die for any philo
void *monitor_routine(void *arg)
{
	t_data		*data;
	long long	curr_time;
	long long	time_since_last_meal;
	int			all_eaten;
	int			i;

	data = (t_data *)arg;
	while (!data->simulation_stop)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			curr_time = get_current_time_in_ms();
			
			pthread_mutex_lock(&data->meal_mutex);
			time_since_last_meal = curr_time - data->philos[i]->last_meal_time;
			pthread_mutex_unlock(&data->meal_mutex);
			
			if (time_since_last_meal > data->tt_die)
			{
				pthread_mutex_lock(&data->simulation_mutex);
				printf("%lld %d died\n", curr_time - data->start_time, data->philos[i]->id + 1);
				data->simulation_stop = 1; //check into philo's routine too #TODO
				pthread_mutex_unlock(&data->simulation_mutex);
				break ;
			}
		}

		if (data->must_eat_count > 0)
		{
			all_eaten = 1;
			i = -1;
			pthread_mutex_lock(&data->meal_mutex);
			while (++i < data->num_philos)
			{
				if (data->philos[i]->meals_eaten < data->must_eat_count)
				{
					all_eaten = 0;
					break ;
				}
			}
			pthread_mutex_unlock(&data->meal_mutex);
			if (all_eaten)
			{
				pthread_mutex_lock(&data->simulation_mutex);
				data->simulation_stop = 1;
				pthread_mutex_unlock(&data->simulation_mutex);
			}
		}
		usleep(1000);
	}
	return (NULL);
}

void	start_dinner(t_data *data)
{
	int			i;
	pthread_t	monitor;
	//...

	/* CHECK SPECIAL CASES */
	// if (data->must_eat_count == 0) // && argc == 5 | 0 != NULL, means explicitly add it
	// 	return ;
	// else if (data->num_philos == 1)
	//	handle_single_philo();
	
	/* LOOP INIT PHILOS MUTEXES(0) */
	i = -1;
	while (++i < data->num_philos)
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (EXIT_FAILURE); //handle_error()

	/* INIT SHARE DATA MUTEXES */
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0
		|| pthread_mutex_init(&data->simulation_mutex, NULL) != 0)
		return (EXIT_FAILURE);

	/* START SIMULATION TIME & PHILOS LAST_MEAL_TIME */
	data->start_time = get_current_time_in_ms();

	i = -1;
	while (++i < data->num_philos)
		data->philos[i].last_meal_time = data->start_time; // not get_current_time_in_ms();
	//update(write) just after printf(eating), inside philo's routine, wrapped by mutex(shared data)

	/* MONITOR BEFORE PHILOS ROUTINES*/
	if (pthread_create(&monitor, NULL, &monitor_routine, &data) != 0)
		return (EXIT_FAILURE);

	/* LOOP THREADS CREATE(1) ROUTINES */
	i = -1;
	while (++i < data->num_philos)
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data) != 0)
			return (EXIT_FAILURE);

	/* LOOP THREADS JOIN(2) ROUTINES */
	i = -1;
	while (++i < data->num_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (EXIT_FAILURE);
	
	/* JOIN MONITOR LAST */
	if (pthread_join(monitor, NULL) != 0)
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
		start_dinner(&data);
	}
	else
		printf("Invalid number of args.\n");
	return (EXIT_SUCCESS);
}
