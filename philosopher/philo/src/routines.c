/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:16:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/23 11:42:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*single_routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;

	philo = (t_philo*)arg;
	while (!philo->data->simulation_stop)
	{
		curr_time = get_current_time_in_ms();
		pthread_mutex_lock(&philo->left_fork->fork);
		printf("%ld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);
		pthread_mutex_unlock(&philo->left_fork->fork);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;
	t_mtx	first_fork;
	t_mtx	second_fork;

	philo = (t_philo *)arg;
	while (!philo->data->simulation_stop)
	{
		/* THINK */
		curr_time = get_current_time_in_ms();
		printf("%ld %d is thinking\n", curr_time - philo->data->start_time, philo->id);
		usleep(10);

		/* MIN-MAX */
		if (philo->left_fork->id < philo->right_fork->id)
		{
			first_fork = philo->left_fork->fork;
			second_fork = philo->right_fork->fork;
		}
		else
		{
			first_fork = philo->right_fork->fork;
			second_fork = philo->left_fork->fork;
		}
		
		/* TAKE 2 FORKS - lower 1rst / higher 2nd */
		handle_mutex(&first_fork, LOCK);
		curr_time = get_current_time_in_ms();
		printf("%ld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);
		handle_mutex(&second_fork, LOCK);
		curr_time = get_current_time_in_ms();
		printf("%ld %d has taken a fork\n", curr_time - philo->data->start_time, philo->id);

		/* EAT */
		curr_time = get_current_time_in_ms();
		printf("%ld %d is eating\n", curr_time - philo->data->start_time, philo->id);
		precise_usleep(philo->data->tt_eat);
		philo->last_meal_time = get_current_time_in_ms();
		philo->meals_eaten++;

		/* DROP 2 FORKS */
		handle_mutex(&second_fork, UNLOCK);
		handle_mutex(&first_fork, UNLOCK);

		/* SLEEP */
		curr_time = get_current_time_in_ms();
		printf("%ld %d is sleeping\n", curr_time - philo->data->start_time, philo->id);
		usleep(philo->data->tt_sleep);
	}
	return (NULL);
}

void *monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!data->simulation_stop)
	{
		is_philos_all_eaten(data);
		is_philo_died(data);
		usleep(1000);
	}
	return (NULL);
}
