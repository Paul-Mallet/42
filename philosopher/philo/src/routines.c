/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:16:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/01 22:05:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*single_routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;

	philo = (t_philo*)arg;
	printf("\nsimulation_stop in single_routine: %d\n", philo->data->simulation_stop);
	while (1)
	{
		handle_mutex(&philo->data->read_mutex, LOCK);
		if (philo->data->simulation_stop) //not enter inside it
		{
			handle_mutex(&philo->data->read_mutex, UNLOCK);
			break ;
		}
		handle_mutex(&philo->data->read_mutex, UNLOCK);
		precise_usleep(500);

		curr_time = get_current_time_in_ms();
		handle_mutex(&philo->left_fork->fork, LOCK);
		printf("\nphilo->id: %u\nphilo->left_fork_id: %u\n", philo->id, philo->left_fork->id);
		printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time), philo->id);
		handle_mutex(&philo->left_fork->fork, UNLOCK);
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
		handle_mutex(&philo->philo_mutex, LOCK);
		printf("%ld %d is thinking\n", curr_time - philo->data->start_time, philo->id);
		handle_mutex(&philo->philo_mutex, UNLOCK);
		precise_usleep(10);

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
		handle_mutex(&philo->philo_mutex, LOCK);
		printf("%ld %d is eating\n", curr_time - philo->data->start_time, philo->id);
		handle_mutex(&philo->philo_mutex, UNLOCK);
		precise_usleep(philo->data->tt_eat);
		
		handle_mutex(&philo->data->write_mutex, LOCK);
		philo->last_meal_time = get_current_time_in_ms();
		philo->meals_eaten++;
		handle_mutex(&philo->data->write_mutex, UNLOCK);

		/* DROP 2 FORKS */
		handle_mutex(&second_fork, UNLOCK);
		handle_mutex(&first_fork, UNLOCK);

		/* SLEEP */
		curr_time = get_current_time_in_ms();
		handle_mutex(&philo->philo_mutex, LOCK);
		printf("%ld %d is sleeping\n", curr_time - philo->data->start_time, philo->id);
		handle_mutex(&philo->philo_mutex, UNLOCK);
		precise_usleep(philo->data->tt_sleep);
	}
	return (NULL);
}

void *monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	printf("\ndata->num_philos in monitor_routine: %d\n", data->num_philos);
	while (1)
	{
		printf("test in monitor\n");
		handle_mutex(&data->read_mutex, LOCK);
		if (data->simulation_stop) //not enter inside it
		{
			handle_mutex(&data->read_mutex, UNLOCK);
			break ;
		}
		handle_mutex(&data->read_mutex, UNLOCK);
		precise_usleep(500);

		is_philos_all_eaten(data);
		is_philo_died(data);
		precise_usleep(500);
	}
	return (NULL);
}
