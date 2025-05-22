/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:16:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 12:40:19 by pamallet         ###   ########.fr       */
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

	data = (t_data *)arg;
	pthread_mutex_lock(&data->stop_mutex);
	while (!data->simulation_stop)
	{
		is_philos_all_eaten(data);
		is_philo_died(data);
		usleep(1000);
	}
	pthread_mutex_unlock(&data->stop_mutex);
	return (NULL);
}
