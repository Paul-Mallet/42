CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar -rcs $(OBJS) $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
