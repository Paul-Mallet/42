/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:46:45 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/06 18:55:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
	char *msg: message to print
	exit the program with failure status code
*/
int	error_exit(const char *msg, int status)
{
	printf("%s\n", msg);
	return (status);
}

/*
	t_err_code code: enum error code based on mutex function manual 
*/
int	handle_input_error(t_err code)
{
	if (code == EMPTY_ERR)
		return (error_exit("Invalid empty input.", code));
	else if (code == SPACES_ERR)
		return (error_exit("Invalid only spaces input.", code));
	else if (code == DIGITS_ERR)
		return (error_exit("Invalid digits format.", code));
	else if (code == SIGN_ERR)
		return (error_exit("Invalid sign, not handle.", code));
	else if (code == OVERFLOW_ERR)
		return (error_exit("Invalid type, only handle unsigned int.", code));
	return (SUCCESS);
}

/*
	int status: status code returned by pthread_mutex functions
	t_err_code code: enum error code based on mutex function manual
*/
void	handle_mutex_error(int status, t_err code)
{
	if (status == 0)
		return ;
	else if (status == EINVAL
		&& (code == LOCK || code == UNLOCK || code == DESTROY))
		error_exit("The value specified by mutex is invalid.", code);
	else if (status == EINVAL && code == INIT)
		error_exit("The value specified by attr is invalid.", code);
	else if (status == EBUSY)
		error_exit("Mutex is locked.", code);
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.", code);
	else if (status == EDEADLK)
	{
		error_exit("A deadlock would occur if the thread"
			"blocked waiting for mutex.", code);
	}
	else if (status == ENOMEM)
	{
		error_exit("The process cannot allocate enough"
			"memory to create another mutex.", code);
	}
}

/*
	int status: status code returned by pthread_mutex functions
	t_err_code code: enum error code based on mutex function manual
*/
void	handle_thread_error(int status, t_err code)
{
	if (code == CREATE)
	{
		if (status == EINVAL)
			error_exit("Invalid settings in attr.", code);
		else if (status == EPERM)
		{
			error_exit("No permission to set the scheduling policy"
				" and parameters specified in attr.", code);
		}
	}
	else if (code == JOIN)
	{
		if (status == EDEADLK)
		{
			error_exit("A  deadlock  was  detected (e.g., two threads  tried"
				" to  join  with   each other); or thread specifies the call‐"
				"ing thread.", code);
		}
		else if (status == EINVAL)
			error_exit("thread is not a joinable thread.", code);
		else if (status == ESRCH)
			error_exit("No thread with the ID thread could be found.", code);
	}
}
