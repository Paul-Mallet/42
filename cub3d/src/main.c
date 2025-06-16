/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:27:54 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/16 18:36:51 by pamallet         ###   ########.fr       */
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

// void	init_data(t_data *data)
// {
// 	data->mlx.name = 
// }

void	init(t_data *data)
{
	data->mlx.mlx_co = mlx_init();
	// if (!data->mlx.mlx_co)
	// 	handle_err("Malloc error.");
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_co,
		WIDTH, HEIGHT, data->mlx.name);
	// if (!data->mlx.mlx_win)
	// {
	// 	mlx_destroy_display(data->mlx.mlx_co);
	// 	free(data->mlx.mlx_co);
	// 	handle_err("Malloc error.");
	// }
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_co, WIDTH, HEIGHT);
	// if (!data->img.img_ptr)
	// {
	// 	mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
	// 	mlx_destroy_display(data->mlx.mlx_co);
	// 	free(data->mlx.mlx_co);
	// 	handle_err("Malloc error.");
	// }
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.bpp, &data->img.line_len, &data->img.endian);
	// init_data(data);
	mlx_loop(data->mlx.mlx_co);
}

int	main(int ac, char **av)
{
	//float = float_t = FLT_EVAL_METHOD 0 = 4 bytes = 32 bits
	//double = double_t = FLT_EVAL_METHOD 0 = 8 bytes = 64 bits
	float		flt = 4.2;
	double		dble = 4.2;
	float_t		fltt1 = 4.2;
	double_t	dblet1 = 4.2;
	t_data		data;

	/* FLOAT & DOUBLE */
	printf("FLT_EVAL_METHOD: %d\n", __FLT_EVAL_METHOD__);
	printf("float: %f sizeof(%ld) min(%f)\n", flt, sizeof(flt), FLT_MIN);
	printf("float_t1: %f sizeof(%ld) max(%f)\n", fltt1, sizeof(fltt1), FLT_MAX);
	printf("double: %f sizeof(%ld) min(%f)\n", dble, sizeof(dble), DBL_MIN);
	printf("double_t1: %f sizeof(%ld) max(%f)\n", dblet1, sizeof(dblet1), DBL_MAX);
	
	/* MATH */
	//acos, asin, atan()... need input [-1, 1] domain
	printf("acos: %f, can return %f\n", acos(dble), NAN);
	printf("acos: %f\n", my_clamped_formula(acos, dble));
	printf("acos: %f\n", my_clamped_formula(acos, M_PI_4));
	
	/* flags chars for doubles */
	// 5 spaces + 24000
	printf("*: %*d\n", 10, 24000);
	printf(".1: %.1f\n", 1234567.89);

	/* Error Handling */
	if (math_errhandling & MATH_ERRNO)
		printf("Math functions set errno\n");
	if (math_errhandling &  MATH_ERREXCEPT)
		printf("Math functions raise floating-point exceptions\n");

	(void)ac;
	data.mlx.name = av[1]; //change with *.cub
	init(&data);
	// render(&data);

	// /* perror + errno set + exit */
	// int 	pfd;
	// char 	*pathname = "/tmp/file";

	// if ((pfd = open(pathname, O_RDONLY)) == -1)
	// {
	// 	perror("Cannot open file\n");
	// 	exit(EXIT_FAILURE);
	// }

	return (0);
}