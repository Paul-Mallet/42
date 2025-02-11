CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=main.c
OBJS=$(SRCS:.c=.o)
NAME=pipex

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re