CC=cc
FLAGS=-Wall -Wextra -Werror
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), \
	main.c \
     init.c \
     operations.c \
     log_ops.c \
     print_log_ops.c \
     print_log_ops2.c \
     cheapi.c \
     count1.c \
     count2.c \
     sorts1.c \
     sorts2.c \
     sorts3.c \
     utils1.c \
     utils2.c \
     utils3.c \
     free.c)
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
NAME_1=./libft/libft.a
NAME_2=push_swap

all: $(NAME_2)

$(NAME_2): $(OBJS) $(NAME_1)
	$(CC) $(FLAGS) -g $(OBJS) -L./libft -lft -o $(NAME_2)

$(NAME_1):
	$(MAKE) -C ./libft

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -g -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJ_DIR)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_2)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
