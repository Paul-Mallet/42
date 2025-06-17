CC=cc
CFLAGS=-Wall -Wextra -Werror -g -Iincludes -I/usr/include -Iminilibx-linux
LDFLAGS=-lm -Lminilibx-linux -lmlx_Linux -lXext -lX11
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR), \
		main.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
NAME=cub3D

all: $(NAME)
	@echo "Cub3D compiled"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

#-03 opti mlx perf?

clean:
	@rm -rf $(OBJS_DIR)
	@echo "objs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "bin cleaned"

re: fclean all

.PHONY: all clean fclean re