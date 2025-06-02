/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:16:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/02 18:45:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*single_routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;

	philo = (t_philo*)arg;
	curr_time = get_current_time_in_ms();
	handle_mutex(&philo->left_fork->fork, LOCK);
	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time), philo->id);
	handle_mutex(&philo->left_fork->fork, UNLOCK);
	while (1)
	{
		if (is_simulation_stopped(philo->data))
			break ;
		precise_usleep(500);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	// time_t	curr_time;
	// t_mtx	first_fork;
	// t_mtx	second_fork;

	//inf loop not from here !!!
	philo = (t_philo *)arg;
	printf("\nphilo id: %u\n", philo->id);
	// while (1)
	// {
	// 	// if (is_simulation_stopped(philo->data))
	// 	// 	break ;

	// 	/* MIN-MAX FORKS */
	// 	if (philo->left_fork->id < philo->right_fork->id)
	// 	{
	// 		first_fork = philo->left_fork->fork;
	// 		second_fork = philo->right_fork->fork;
	// 	}
	// 	else
	// 	{
	// 		first_fork = philo->right_fork->fork;
	// 		second_fork = philo->left_fork->fork;
	// 	}

	// 	/* TAKE 2 FORKS - lower 1rst / higher 2nd */
	// 	handle_mutex(&first_fork, LOCK);
	// 	curr_time = get_current_time_in_ms();
	// 	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time), philo->id);
	// 	handle_mutex(&second_fork, LOCK);
	// 	curr_time = get_current_time_in_ms();
	// 	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time), philo->id);

	// 	/* EAT */
	// 	curr_time = get_current_time_in_ms();
	// 	handle_mutex(&philo->philo_mutex, LOCK);
	// 	printf("%ld %d is eating\n", (curr_time - philo->data->start_time), philo->id);
	// 	handle_mutex(&philo->philo_mutex, UNLOCK);
	// 	precise_usleep(philo->data->tt_eat);
	// 	// UPDATE LAST_MEAL & MEALS_EATEN OF CURR PHILO
	// 	handle_mutex(&philo->data->write_mutex, LOCK);
	// 	philo->last_meal_time = get_current_time_in_ms();
	// 	philo->meals_eaten++;
	// 	handle_mutex(&philo->data->write_mutex, UNLOCK);
	// 	/* DROP 2 FORKS */
	// 	handle_mutex(&second_fork, UNLOCK);
	// 	handle_mutex(&first_fork, UNLOCK);

	// 	/* SLEEP */
	// 	curr_time = get_current_time_in_ms();
	// 	handle_mutex(&philo->philo_mutex, LOCK);
	// 	printf("%ld %d is sleeping\n", (curr_time - philo->data->start_time), philo->id);
	// 	handle_mutex(&philo->philo_mutex, UNLOCK);
	// 	precise_usleep(philo->data->tt_sleep);
		
	// 	/* THINK */
	// 	curr_time = get_current_time_in_ms();
	// 	handle_mutex(&philo->philo_mutex, LOCK);
	// 	printf("%ld %d is thinking\n", curr_time - philo->data->start_time, philo->id);
	// 	handle_mutex(&philo->philo_mutex, UNLOCK);
	// 	precise_usleep(10);
	// }
	return (NULL);
}

void *monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	printf("\ndata->num_philos in monitor_routine: %d\n", data->num_philos);
	while (1)
	{
		// printf("monitor_routine\n");
		is_philos_all_eaten(data);
		is_philo_died(data);		
		if (is_simulation_stopped(data))
			break ;
		precise_usleep(500);
	}
	return (NULL);
}
