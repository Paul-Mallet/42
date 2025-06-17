/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:38:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/17 17:19:56 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	my_clamped_formula(double (*formula)(double), double input)
{
	double	res;

	if (input > 1)
		input = 1.0;
	if (input < 1)
		input = -1.0;
	res = formula(input);
	return (res);
}
