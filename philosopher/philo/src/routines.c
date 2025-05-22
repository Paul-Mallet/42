/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:16:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 08:19:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*single_routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;

	philo = (t_philo*)arg;
	pthread_mutex_lock(&philo->data->stop_mutex);
	while (!philo->data->simulation_stop)
	{
		curr_time = get_current_time_in_ms();
		pthread_mutex_lock(&philo->left_fork->fork);
		printf("%ld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->left_fork->fork);
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;

	philo = (t_philo*)arg;
	pthread_mutex_lock(&philo->data->stop_mutex);
	while (!philo->data->simulation_stop)
	{
		/* THINK */
		curr_time = get_current_time_in_ms();
		printf("%ld %d is thinking\n", curr_time - philo->data->start_time, philo->id);
		usleep(10);
		
		/* TAKE 2 FORKS - lower 1rst / higher 2nd */
		pthread_mutex_lock(&philo->left_fork->fork);
		curr_time = get_current_time_in_ms();
		printf("%ld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);
		pthread_mutex_lock(&philo->right_fork->fork);
		curr_time = get_current_time_in_ms();
		printf("%ld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);

		/* EAT */
		curr_time = get_current_time_in_ms();
		printf("%ld %d is eating\n", curr_time - philo->data->start_time, philo->id);
		usleep(philo->data->tt_eat);
		pthread_mutex_lock(&philo->data->meal_mutex);
		philo->last_meal_time = get_current_time_in_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		// no more than "10 ms after"

		/* DROP 2 FORKS */
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);

		/* SLEEP */
		curr_time = get_current_time_in_ms();
		printf("%ld %d is sleeping\n", curr_time - philo->data->start_time, philo->id);
		usleep(philo->data->tt_sleep);
	}
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (NULL);
}

void *monitor_routine(void *arg)
{
	t_data	*data;
	time_t	curr_time;
	time_t	time_since_last_meal;
	bool	all_eaten;
	int		i;

	data = (t_data *)arg;
	pthread_mutex_lock(&data->stop_mutex);
	while (!data->simulation_stop)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			curr_time = get_current_time_in_ms();
			
			pthread_mutex_lock(&data->meal_mutex);
			time_since_last_meal = curr_time - data->philos[i].last_meal_time;
			pthread_mutex_unlock(&data->meal_mutex);

			if (time_since_last_meal > data->tt_die)
			{
				curr_time = get_current_time_in_ms();
				pthread_mutex_lock(&data->simulation_mutex);
				printf("%lld %d died\n", curr_time - data->start_time, data->philos[i].id);
				data->simulation_stop = true;
				pthread_mutex_unlock(&data->simulation_mutex);
				break ;
			}
		}

		if (data->must_eat_count > 0)
		{
			all_eaten = true;
			i = -1;

			pthread_mutex_lock(&data->meal_mutex);
			while (++i < data->num_philos)
			{
				if (data->philos[i].meals_eaten < data->must_eat_count)
				{
					all_eaten = false;
					break ;
				}
			}
			pthread_mutex_unlock(&data->meal_mutex);

			if (all_eaten)
			{
				pthread_mutex_lock(&data->simulation_mutex);
				data->simulation_stop = true;
				pthread_mutex_unlock(&data->simulation_mutex);
			}
		}
		usleep(1000);
	}
	pthread_mutex_unlock(&data->stop_mutex);
	return (NULL);
}
