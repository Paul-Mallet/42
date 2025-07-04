/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:18:26 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/04 15:55:21 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <fcntl.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <inttypes.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <errno.h>
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define _GNU_SOURCE

//macros
# define S_WIDTH	720
# define S_HEIGHT	480

// wall, ceil, floor textures and resolutions
// only handle 64x64? so return error if not at proper size in parsing
# define TEX_NUM	4
# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define MAP_WIDTH	24
# define MAP_HEIGHT	24

# define X_STR		4
# define Y_STR		4

# define M_PI 3.14159265358979323846

# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define BLACK		0x000000
# define WHITE		0xFFFFFF

//enums
typedef enum e_err
{
	SUCCESS, // 0
	// lib functions
	MALLOC,
	// syst calls
	OPEN,
	CLOSE,
	READ,
	WRITE,
	TIME,
	// mlx
	INIT,
	WINDOW,
	IMAGE,
	// Math.h
	IS_HUGE_VAL,
	IS_INFINITY,
	IS_NAN,
	//...
}	t_err;

typedef struct s_mlx
{
	void	*mlx_co;
	void	*mlx_win;		//
	char	*name;			//screen name
}	t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_wall
{
	bool	is_hit;			//hit a wall(== 1)
	bool	which_side;		//0 = North/South(x), 1 = East/West(y)
}	t_wall;

/*
	// curr map's square we're in([screen.width x screen.height]?)
	int				map_x;		//(int)player.pos_x = 0(floor, min)
	int				map_y;		//(int)player.pos_y = 23(map_height - 1, max),
								if (double)player.posX = 22.999999
*/
typedef struct s_grid
{
	int				map_x;
	int				map_y;
	t_wall			wall;
}	t_grid;

/*
	double	camera_x;	//=2 * x / w - 1;, [-1(left), 0(center), 1(right)]
*/
typedef struct s_cam
{
	double	plane_x;		//0
	double	plane_y;		//0.66
	double	old_plane_x;	//saved state of cam.plane_x
	double	camera_x;
}	t_cam;

typedef struct s_screen
{
	//(0;0) = top-left corner
	int		x;				//x = width axe
	int		y;				//y = height axe
}	t_screen;

/*
	double	pos_x;	//if (double)player.posX = 0.89(after moving on the map)
	double	fov;	//2 * atan(sqrt(cam.planeX ^ 2 + cam.planeY ^ 2) /
					sqrt(player.dirX ^ 2 + player.dirY ^ 2)) = N°
*/
typedef struct s_player
{
	//start pos will be full values(22, 12) based on grid
	double	pos_x;
	double	pos_y;			//change after each move
	double	dir_x;			//-1, vector x coord
	double	dir_y;			//0, vector y coord
	double	old_dir_x;		//saved state of prev dir_x
	//Pythagorean Theorem = sqrt(x ^ 2 + y ^ 2) = vector length;
	double	fov;
}	t_player;

/*
	double	side_dist_y;	//(mapY + 1.0 - ray.posY) *
							deltaDistY;, if ray.dirY >= 0
	double	delta_dist_x;	//abs(1 / ray.dirX);
							|| INF(avoid / 0), if ray.dirX == 0
	double	delta_dist_y;	//abs(1 / ray.dirY);
							|| INF(avoid / 0), if ray.dirY == 0
*/
typedef struct s_ray
{
	double	pos_x;			//start at player.posX
	double	pos_y;			//player.posY
	double	dir_x;			//player.dirX + cam.planeX * cam.cameraX
	double	dir_y;			//player.dirY + cam.planeY * cam.cameraX
	int		step_x;			//-1, if ray.dirX < 0
	int		step_y;			//+1, if ray.dirY >= 0
	double	side_dist_x;	//(ray.posX - mapX) * deltaDistX;, if ray.dirX < 0
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;	//ray dist length
	float	dir_x_left;		//x leftmost point
	float	dir_x_right;	//x rightmost point
	float	dir_y_left;		//y ...
	float	dir_y_right;	//y ...
}	t_ray;

/*
	draw walls textures as vertical line from top to bottom
*/
typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
}	t_draw;

/*
	speed modifiers of movements and rotations of the player
*/
typedef struct s_speed
{
	double	mov;
	double	rot;
}	t_speed;

/*
	current and next compute calculation
*/
typedef struct s_keys
{
	int	close;
	int	up;
	int	down;
	int	left;
	int	right;
	int	left_dir;
	int	right_dir;
	int	curr_map_x;
	int	curr_map_y;
	int	next_map_x_up;
	int	next_map_x_down;
	int	next_map_x_left;
	int	next_map_x_right;
	int	next_map_y_up;
	int	next_map_y_down;
	int	next_map_y_left;
	int	next_map_y_right;
	int	next_player_dir_x_right;
	int	next_player_dir_y_right;
	int	next_player_dir_x_left;
	int	next_player_dir_y_left;
}	t_keys;

/*

*/
typedef struct s_tex
{
	int			xorcolor;
	int			xcolor;
	int			ycolor;
	int			xycolor;
	int			tex_index;
	double		wall_x;
	int			x;
	int			y;
	int			y_tex_buff;
	double		step;
	double		pos;
	// maybe could use t_img instead
	void		*tex_img;
	char		*tex_addr;
	int			tex_bpp;
	int			tex_line_len;
	int			tex_endian;
	//---
	int			floor_x;
	int			floor_y;
	u_int32_t	color;
}	t_tex;

/*

*/
// floor / ceiling coordinates based on camera and distances
typedef struct s_floor
{
	int			pos_y;
	float		pos_z;
	float		row_dist;
	float		step_x;
	float		step_y;
	float		x;
	float		y;
	int			cell_x;
	int			cell_y;
}	t_floor;

typedef struct s_fill_data
{
	char		**map;
	int			rows;
	int			cols;
}	t_fill_data;

typedef struct s_parsing
{
	char		**file;
	char		**map;
	int			**map_int;
	int			file_line_number;
	int			map_line_number;
	int			map_col_number;
	t_fill_data	fill;
	int			color_c;
	int			color_f;
	int			player_count;
	int			player_x;
	int			player_y;
	int			is_empty;
	char		*text_so;
	char		*text_no;
	char		*text_ea;
	char		*text_we;
	void		*img_so;
	void		*img_no;
	void		*img_ea;
	void		*img_we;
	char		*orientation;
}	t_parsing;

typedef struct s_data
{
	t_mlx		mlx;
	t_img		img;
	t_grid		grid;
	t_screen	screen;
	t_player	player;
	t_cam		cam;
	t_ray		ray;
	t_draw		draw;
	t_speed		speed;
	t_keys		keys;
	t_tex		tex;
	t_floor		floor;
	t_parsing	parsing;
	int			components[3];
}	t_data;

// PARSING
int			read_file(char *filename, t_data *data);
int			check_format(char *argv);
int			check_letter(t_data *data);
int			count_lines(char *filename, t_data *data);
void		error_map(t_data *data);
int			check_char(char c);
int			ft_isspace(const char c);
int			check_before_rgb(char *line, int i);
int			check_empty_line(t_data *data, int i);
int			get_color(t_data *data, char *line);
int			free_tab(char **tab);
int			verif_textures(t_data *data);
int			read_map(t_data *data, int i);
int			close_game(t_data *data);
int			check_player(t_data *data);
int			check_chars(char *str);
int			check_spaces(t_data *data);
int			check_walls(t_data *data);
void		get_orientation(t_data *data, char c, int x, int y);
int			count_cols(t_data *data);
int			get_textures_and_colors(t_data *data);
void		free_textures_and_images(t_data *data);
int			verif_values(t_data *data);
int			check_space(t_data *data, int i, int j);
int			check_duplicates(char identifier, t_data *data);
int			print_error(t_data *data);
int			check_player_char(char c);
int			check_components(t_data *data, char *line);
int			check_player_surrounded(t_data *data);
int			check_rgb_during(t_data *data, char identifier, int i);

// INIT
void		convert_map_to_int(t_data *data);
void		init(t_data *data);

// RENDER
void		render(t_data *data);

// TEXTURES
int			get_tex_index(t_data *data);
void		generate_textures(t_data *data,
				int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH]);
void		draw_tex_buff(t_data *data,
				u_int32_t tex_buff[S_HEIGHT][S_WIDTH]);
void		clear_tex_buff(t_data *data,
				u_int32_t tex_buff[S_HEIGHT][S_WIDTH]);

// FLOOR & CEILING
void		floor_casting(t_data *data);

// COMPUTE DISTANCES
void		get_next_side_dist(t_data *data);
void		get_init_side_dist(t_data *data);
void		digit_diff_analyzer(t_data *data);

// DRAWING PIXELS
void		draw_my_pixel_line(t_data *data,
				int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH],
				u_int32_t tex_buff[S_HEIGHT][S_WIDTH]);

// HOOKS
int			handle_close(t_data *data);
void		setup_next_moves(t_data *data);
void		handle_up(t_data *data);
void		handle_down(t_data *data);
void		handle_right(t_data *data);
void		handle_left(t_data *data);
void		handle_right_dir(t_data *data);
void		handle_left_dir(t_data *data);
int			handle_keys(t_data *data);
int			handle_keys_press(int key_sym, t_data *data);
int			handle_keys_release(int key_sym, t_data *data);

// UTILS
void		*ft_memset(void *s, int c, size_t n);
int			ft_intlen(int nb);
double		ft_abs(double dir);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		my_clamped_formula(double (*formula)(double), double input);

// ERRORS
void		handle_err(char *msg, t_data *data);

// FREES
void		free_map_int(t_data *data);

// PRINTF
void		print_data(t_data *data);
void		print_map_int(t_data *data);
void		print_map_char(t_data *data);

#endif
