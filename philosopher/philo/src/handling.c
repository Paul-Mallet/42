/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:53:52 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 11:59:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    handle_mutex(t_mtx *fork, t_err_code code)
{
    if (code == INIT_ERR)
        //...
    else if (code == LOCK_ERR)
        //...
    else if (code == UNLOCK_ERR)
        //...
    else if (code == DESTROY_ERR)
        //...
}