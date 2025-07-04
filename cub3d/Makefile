NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -g

MLXFLAGS = -I./minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

OBJDIR = obj
LIBFTDIR = libft
MINILIBXDIR = minilibx-linux

SRCS =  src/parsing/check_colors.c src/parsing/error.c src/parsing/check_letters.c \
		src/parsing/verif_textures.c src/parsing/check_walls.c src/parsing/check_map.c \
		src/parsing/check_player.c src/parsing/check_spaces.c src/parsing/convert_map.c \
		src/parsing/utils_colors.c src/main.c src/utils.c \
		src/parsing/check_colors_utils.c src/exec/init.c src/exec/render.c src/exec/hooks.c \
		src/exec/utils_general.c src/exec/utils_hook.c src/exec/utils_render_floor_casting.c \
		src/exec/utils_render_pixel_line.c src/exec/utils_render_side_dist.c \
		src/exec/utils_render_tex_buff.c src/exec/utils_render_tex_gen.c \
		src/exec/errors.c src/exec/print.c

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a

MINILIBX = $(MINILIBXDIR)/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(LIBFT)
	@echo "\033[32m✔ Compilation completed\033[0m"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)

clean:
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	@echo "\033[33m✔ $(OBJDIR) suppressed\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MINILIBXDIR) clean
	@echo "\033[31m✔ $(NAME), libft.a et libmlx.a suppressed\033[0m"

re: fclean all

.PHONY: all clean fclean re