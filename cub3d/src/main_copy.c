/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:27:54 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/25 19:23:56 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	// char	*relative_path = "test.png";
	// char	*relative_path = "test.xpm";
	static char *xpm_data[] = {
		"8 8 2 1",
		"  c #8B4513",
		". c #A0522D",
		"  . .  .",
		" ... ...",
		". . . . ",
		"... ....",
		"  . .  .",
		" ... ...",
		". . . . ",
		"... ....",
		NULL};
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "xpm test");
	if (!win)
		printf("win problem\n");
	// img = mlx_png_file_to_image(mlx, relative_path, &img_width, &img_height);
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img = mlx_xpm_to_image(mlx, xpm_data, &img_width, &img_height);
	if (!img)
		printf("img problem\n");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

// -Wall -Wextra -Werror -g -Iincludes -I/usr/include -Iminilibx-linux -lm -Lminilibx-linux -lmlx_Linux -lXext -lX11