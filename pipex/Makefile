CC=cc
FLAGS=-Wall -Wextra -Werror
SRC_DIR=src/
SRC=$(addprefix $(SRC_DIR), \
	main.c \
	utils.c \
	syntax.c \
	errors.c)
OBJ_DIR=obj/
OBJ=$(SRC:%.c=$(OBJ_DIR)%.o)
NAME_1=./libft/libft.a
NAME_2=pipex

all: $(NAME_2)

$(NAME_2): $(OBJ) $(NAME_1)
	$(CC) $(FLAGS) -g $(OBJ) -L./libft -lft -o $(NAME_2)

$(NAME_1):
	$(MAKE) -C ./libft

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -g -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_DIR)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_2)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re