CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(OBJS) $(LIBFT) $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
