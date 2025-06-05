/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:30:59 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/05 18:24:59 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// t_mtx	*forks_ordering(t_philo *philo)
// {
// 	t_mtx	*forks;

// 	forks = (t_mtx *)malloc(2 * sizeof(t_mtx));
// 	if (!forks)
// 		error_exit("Malloc failed.");
// 	if (philo->left_fork->id < philo->right_fork->id)
// 	{
// 		forks[0] = philo->left_fork->fork;
// 		forks[1] = philo->right_fork->fork;
// 	}
// 	else
// 	{
// 		forks[0] = philo->right_fork->fork;
// 		forks[1] = philo->left_fork->fork;
// 	}
// 	return (forks);
// }

bool	is_taking_forks(t_philo *philo, t_mtx *fst_fork, t_mtx *sd_fork)
{
	time_t	curr_time;

	handle_mutex(fst_fork, LOCK);
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(fst_fork, UNLOCK);
		return (false);
	}
	curr_time = get_current_time_in_ms();
	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time), philo->id);

	handle_mutex(sd_fork, LOCK);
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(sd_fork, UNLOCK);
		return (false);
	}
	curr_time = get_current_time_in_ms();
	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time),
		philo->id);

	/* EAT */
	if (!is_eating(philo))
		return (false);

	/* DROP 2 FORKS */
	handle_mutex(sd_fork, UNLOCK);
	handle_mutex(fst_fork, UNLOCK);
	return (true);
}

bool	is_eating(t_philo *philo)
{
	time_t  curr_time;

	handle_mutex(&philo->philo_mutex, LOCK);
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(&philo->philo_mutex, UNLOCK);
		return (false);
	}
	curr_time = get_current_time_in_ms();
	printf("%ld %d is eating\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->philo_mutex, UNLOCK);
	handle_mutex(&philo->data->write_mutex, LOCK); //?
	philo->last_meal_time = get_current_time_in_ms();
	handle_mutex(&philo->data->write_mutex, UNLOCK);
	precise_usleep(philo->data->tt_eat * 1000);
	handle_mutex(&philo->data->write_mutex, LOCK);
	philo->meals_eaten++;
	handle_mutex(&philo->data->write_mutex, UNLOCK);
	return (true);
}

bool	is_sleeping(t_philo *philo)
{
	time_t  curr_time;

	handle_mutex(&philo->philo_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(&philo->philo_mutex, UNLOCK);
		return (false);
	}
	printf("%ld %d is sleeping\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->philo_mutex, UNLOCK);
	precise_usleep(philo->data->tt_sleep * 1000);
	return (true);
}

bool	is_thinking(t_philo *philo)
{
	time_t  curr_time;

	handle_mutex(&philo->philo_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(&philo->philo_mutex, UNLOCK);
		return (false);
	}
	printf("%ld %d is thinking\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->philo_mutex, UNLOCK);
	precise_usleep(10);
	return (true);
}