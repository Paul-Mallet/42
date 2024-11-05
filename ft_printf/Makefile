CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
       ft_printchar.c \
       ft_printb10.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
OBJS_LIBFT = $(shell find . -name "*.o")
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS_LIBFT) $(OBJ)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
