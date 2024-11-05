CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printb10.c \
       ft_printchar.c \
#LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
OBJSLIBFT = $(addsuffix /libft)
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
