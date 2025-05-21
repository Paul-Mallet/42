/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:46:45 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 11:37:45 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
    char *msg: message to print
    exit the program with failure status code
*/
void	error_exit(const char *msg)
{
    printf("%s", msg);
    exit(EXIT_FAILURE);
}

/*
    t_err_code code: enum error code based on mutex function manual 
*/
void    handle_input_error(t_err_code code)
{
    if (code == EMPTY_ERR)
		error_exit("Invalid empty input.\n");
	else if (code == SPACES_ERR)
		error_exit("Invalid only spaces input.\n");
	else if (code == DIGITS_ERR)
		error_exit("Invalid digits format.\n");
	else if (code == SIGN_ERR)
		error_exit("Invalid sign, not handle.\n");
	else if (code == OVERFLOW_ERR)
		error_exit("Invalid type, only handle long.\n");
}

/*
    size_t bytes: memory size of value type(int, char, struct...)
*/
void	*handle_malloc_error(size_t bytes)
{
    void    *content;

    content = malloc(bytes);
    if (!content)
        error_exit("Malloc failed. Out of memory.\n");
    return (content);
}

/*
    int(code:(code code returned by pthread_mutex functions
    t_err_code code: enum error code based on mutex function manual
*/
void	handle_mutex_error(int status, t_err_code code)
{
    if (status == 0)
        return ;
    else if (status == EINVAL && (code == LOCK_ERR || code == UNLOCK_ERR || code == DESTROY_ERR))
        error_exit("The value specified by mutex is invalid.\n");
    else if (status == EINVAL && code == INIT_ERR)
        error_exit("The value specified by attr is invalid.\n");
    else if (status == EBUSY)
        error_exit("Mutex is locked.\n");
    else if (status == EPERM)
        error_exit("The current thread does not hold a lock on mutex.\n");
    else if (status == EDEADLK)
        error_exit("A deadlock would occur if the thread blocked waiting for mutex.\n");
    else if (status == ENOMEM)
        error_exit("The process cannot allocate enough memory to create another mutex.\n");
}
