CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
       ft_printchar.c \
       ft_printb10.c \
       ft_printptr.c \
       ft_printhex.c \
       ft_printub10.c \
       ft_putunbr_fd.c \
       ft_uitoa.c \
       ft_uitohex.c \
       ft_ultohex.c \
       ft_puthex_fd.c \
       ft_putaddrs_fd.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
