CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC_DIR=src/
SRC=$(addprefix $(SRC_DIR), \
	main.c)
OBJ_DIR=obj/
OBJ=$(SRC:%.c=$(OBJ_DIR)%.o)
NAME=pipex

all: $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -g $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re