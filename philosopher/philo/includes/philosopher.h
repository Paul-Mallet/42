/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/01 18:28:13 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_msg {
	EMPTY_INPUT_ERR,
	ONLY_SPACES_ERR,
	INVALID_DIGITS_ERR,
	INVALID_SIGN_ERR,
}		t_msg;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			start_time;
	int				nbt_eat;
	int				num_philos;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}		t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	int				is_dead;
}		t_data;

int	parsing(char **av);

int	ft_strlen(const char *s);
int	ft_isspace(const char c);
int	ft_issign(const char c);
int	ft_isdigit(int c);

#endif