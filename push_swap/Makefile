CC=cc
FLAGS=-Wall -Wextra -Werror
SRCS=main.c \
     init.c \
     operations.c \
     sorts.c \
     utils1.c \
     utils2.c
OBJS=$(SRCS:.c=.o)
LIB=libpush_swap.a
NAME=push_swap

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -g -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(LIB) $(OBJS)
	$(CC) $(OBJS) -L. -l$(NAME) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
