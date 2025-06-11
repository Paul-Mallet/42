/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:27:54 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/11 17:45:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_screen()
{
	//...
}

int	main(void)
{
	//float = float_t = FLT_EVAL_METHOD 0 = 4 bytes = 32 bits
	//double = double_t = FLT_EVAL_METHOD 0 = 8 bytes = 64 bits
	float	flt = 4.2;
	double	dble = 4.2;
	float_t	fltt1 = 4.2;
	double_t dblet1 = 4.2;

	/* FLOAT & DOUBLE */
	printf("FLT_EVAL_METHOD: %d\n", __FLT_EVAL_METHOD__);
	printf("float: %f sizeof(%ld) min(%f)\n", flt, sizeof(flt), FLT_MIN);
	printf("float_t1: %f sizeof(%ld) max(%f)\n", fltt1, sizeof(fltt1), FLT_MAX);
	printf("double: %f sizeof(%ld) min(%f)\n", dble, sizeof(dble), DBL_MIN);
	printf("double_t1: %f sizeof(%ld) max(%f)\n", dblet1, sizeof(dblet1), DBL_MAX);
	
	/* MATH */
	printf("acos: %f\n", acos(dble));
	return (0);
}