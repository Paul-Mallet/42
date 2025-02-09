CC=cc
FLAGS=-Wall -Wextra -Werror
SRCS=main.c \
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
     utils1.c \
     utils2.c \
     utils3.c \
     free.c
OBJS=$(SRCS:.c=.o)
NAME_1=./libft/libft.a
NAME_2=push_swap

all: $(NAME_2)

$(NAME_2): $(OBJS) $(NAME_1)
	$(CC) $(FLAGS) -g $(OBJS) -L./libft -lft -o $(NAME_2)

$(NAME_1):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_2)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
