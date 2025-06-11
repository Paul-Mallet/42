CC=cc
FLAGS=-Wall -Wextra -Werror -g -Iincludes
MATHF=-lm
MLXF=-Lminilibx-linux -lmlx_Linux
X11F=-lXext -lX11
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR), \
		main.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
NAME=cub3D

all: $(NAME)
	@echo "Cub3D compiled"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MATHF) $(MLXF) $(X11F) -o $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@
#-03

clean:
	@rm -rf $(OBJS_DIR)
	@echo "objs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "bin cleaned"

re: fclean all

.PHONY: all clean fclean re