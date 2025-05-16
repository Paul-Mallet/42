/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/16 15:59:48 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_msg {
	EMPTY_INPUT_ERR,
	ONLY_SPACES_ERR,
	INVALID_DIGITS_ERR,
	INVALID_SIGN_ERR,
	INVALID_OVERF_ERR,
}		t_msg;

typedef struct s_philo
{
    int             id;                   // Philosopher ID (0 to num_philos-1)
    int             meals_eaten;          // Counter for meals eaten
    long long       last_meal_time;       // Timestamp of last meal(time_to_think, time_to_eat, time_to_sleep?)
    pthread_t       thread;               // Thread ID
    t_data          *data;                // Pointer to shared data
} t_philo;

typedef struct s_data
{
	int				num_philos;			  // 1rst arg
	int				tt_die;				  // 2nd arg
	int				tt_eat;				  // 3rd arg
	int				tt_sleep;		  	  // 4th arg
	int				must_eat_count;       // Optional(5th arg): number of times each philosopher must eat
	int				simulation_stop;      // Flag to stop simulation(simulation_is_over())
	long long		start_time;           // Simulation start timestamp
	// t_philo		*philos;              // Array of philos threads
	pthread_mutex_t	*forks;               // Array of fork mutexes
	pthread_mutex_t write_mutex;          // For synchronized console output
	pthread_mutex_t meal_mutex;           // For updating meal timestamps safely
} t_data;

/* PARSING */
int		parsing(char **av);

/* PARSING_UTILS */
int		ft_strlen(const char *s);
int		ft_isspace(const char c);
int		ft_issign(const char c);
int		ft_isdigit(int c);
int		is_overflow(char *s);

/* CONVERSION_UTILS */
int		ft_atoi(const char *nptr);

/* HANDLE_DATA */
void	init_data(t_data *data, char **av);
int		check_data(t_data *data);

/* PRINT_DATA */
void	print_data(t_data *data);
void	print_philos(t_philo *philos);
void	print_forks(pthread_mutex_t *forks);

#endif