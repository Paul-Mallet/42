CC=cc
FLAGS=-Wall -Wextra -Werror
SRCS=main.c \
     init.c \
     operations.c \
     log_ops.c \
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
NAME_2=libpush_swap.a
EXEC=push_swap

all: $(NAME_1) $(NAME_2)

$(NAME_1):
	$(MAKE) -C ./libft

%.o:%.c
	$(CC) $(FLAGS) -g -c $< -o $@

$(NAME_2): $(OBJS)
	cp $(NAME_1) $(NAME_2)
	ar -rcs $(NAME_2) $(OBJS)

exec:
	$(CC) $(OBJS) -L. -lpush_swap -o $(EXEC)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf $(NAME_2)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
