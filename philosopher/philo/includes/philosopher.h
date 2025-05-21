/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 17:01:15 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>

typedef pthread_mutex_t	t_mtx;

typedef enum e_err_code {
	/* PARSING ERRORS */
	EMPTY_ERR,
	SPACES_ERR,
	DIGITS_ERR,
	SIGN_ERR,
	OVERFLOW_ERR,
	/* MUTEX ERRORS */
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	/* THREAD ERRORS */
	CREATE,
	JOIN,
	DETACH
} t_err_code;

typedef struct s_fork
{
	int		id;
	t_mtx	fork;
} t_fork;

typedef struct s_philo
{
    int			id;                   // Philosopher ID (0 to num_philos-1)
    int			meals_eaten;          // Counter for meals eaten(to reach must_eat_count)
    t_fork		*left_fork;			  // Min fork id, always taking 1rstly
    t_fork		*right_fork;		  // Max fork id, always taking 2ndly
    long		last_meal_time;       // Timestamp of last meal(started before philos thread creations, updated during routine)
	pthread_t	thread;               // Thread ID
    t_data		*data;                // Pointer to shared data
} t_philo;

typedef struct s_data
{
	unsigned int	num_philos;			  // 1rst arg
	unsigned int	tt_die;				  // 2nd arg
	unsigned int	tt_eat;				  // 3rd arg
	unsigned int	tt_sleep;		  	  // 4th arg
	unsigned int	must_eat_count;       // Optional(5th arg): number of times each philosopher must eat
	bool			simulation_stop;      // Flag to stop simulation(simulation_is_over())
	long			start_time;           // Simulation start timestamp
	t_fork			*forks;               // Array of fork mutexes
	t_philo			*philos;              // Array of philos threads
	/* MUTEXES TO ACCESS SHARED DATA */
	t_mtx 			meal_mutex;        	  // For writing and reading meal timestamps safely
	t_mtx 			simulation_mutex;     // For synchronized console output
} t_data;

/* PARSING */
void		parsing(char **av);

/* DATA */
void		init_data(t_data *data, char **av);

/* HANDLING */
void    	handle_mutex(t_mtx *fork, t_err_code code);
//handle_thread(p_thread...);

/* ERRORS */
void		*handle_malloc_error(size_t bytes);
void		handle_mutex_error(int status, t_err_code code);
void		error_exit(const char *msg);

/* CLEAN */
// void		free_data(t_data *data);

/* PARSING_UTILS */
int			ft_strlen(const char *s);
int			ft_isspace(const char c);
int			ft_issign(const char c);
int			ft_isdigit(int c);
int			is_overflow(char *s);

/* CONVERSION_UTILS */
int			ft_atoi(const char *nptr);

/* TIMESTAMP UTILS */
long		get_current_time_in_ms();

/* PRINT_DATA(DEBUG) */
void		print_data(t_data *data);

#endif