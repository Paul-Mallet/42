/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:46:45 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 17:19:53 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
    char *msg: message to print
    exit the program with failure status code
*/
void	error_exit(const char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

/*
    t_err_code code: enum error code based on mutex function manual 
*/
void    handle_input_error(t_err_code code)
{
    if (code == EMPTY_ERR)
		error_exit("Invalid empty input.");
	else if (code == SPACES_ERR)
		error_exit("Invalid only spaces input.");
	else if (code == DIGITS_ERR)
		error_exit("Invalid digits format.");
	else if (code == SIGN_ERR)
		error_exit("Invalid sign, not handle.");
	else if (code == OVERFLOW_ERR)
		error_exit("Invalid type, only handle long.");
}

/*
    size_t bytes: memory size of value type(int, char, struct...)
*/
void	*handle_malloc_error(size_t bytes)
{
    void    *content;

    content = malloc(bytes);
    if (!content)
        error_exit("Malloc failed. Out of memory.");
    return (content);
}

/*
    int status: status code returned by pthread_mutex functions
    t_err_code code: enum error code based on mutex function manual
*/
void	handle_mutex_error(int status, t_err_code code)
{
    if (status == 0)
        return ;
    else if (status == EINVAL && (code == LOCK || code == UNLOCK || code == DESTROY))
        error_exit("The value specified by mutex is invalid.");
    else if (status == EINVAL && code == INIT)
        error_exit("The value specified by attr is invalid.");
    else if (status == EBUSY)
        error_exit("Mutex is locked.");
    else if (status == EPERM)
        error_exit("The current thread does not hold a lock on mutex.");
    else if (status == EDEADLK)
        error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
    else if (status == ENOMEM)
        error_exit("The process cannot allocate enough memory to create another mutex.");
}

/*
    ???
    int status: status code returned by pthread_mutex functions
    t_err_code code: enum error code based on mutex function manual
*/
void    handle_thread_error(int status, t_err_code code)
{
    if (status == 0)
        return ;
    else if (code == CREATE)
    {
        if (status == EINVAL)
            error_exit("Invalid settings in attr.");
        else if (status == EPERM)
        {
            error_exit("No permission to set the scheduling policy"
                " and parameters specified in attr.");    
        }
    }
    else if (code == JOIN && status == EDEADLK)
    {
        error_exit("A  deadlock  was  detected (e.g., two threads  tried"
            " to  join  with   each other); or thread specifies the call‐"
            "ing thread.");
    }
    else if (code == JOIN || code == DETACH)
    {
        if (status == EINVAL)
            error_exit("thread is not a joinable thread.");
        else if (status == ESRCH)
            error_exit("No thread with the ID thread could be found.");
    }
}
