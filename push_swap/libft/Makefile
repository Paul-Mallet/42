CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_issign.c \
	 ft_isspace.c \
	 ft_isalpha.c \
	 ft_isdigit.c \
	 ft_isalnum.c \
	 ft_isascii.c \
	 ft_isprint.c \
	 ft_memset.c \
	 ft_bzero.c \
	 ft_memcpy.c \
	 ft_memmove.c \
	 ft_toupper.c \
	 ft_tolower.c \
	 ft_strlen.c \
	 ft_strchr.c \
	 ft_strncmp.c \
	 ft_memchr.c \
	 ft_memcmp.c \
	 ft_strnstr.c \
	 ft_calloc.c \
	 ft_split.c \
	 ft_itoa.c \
	 ft_striteri.c \
	 ft_putchar_fd.c \
	 ft_putstr_fd.c \
	 ft_putendl_fd.c \
	 ft_putnbr_fd.c \
	 ft_printf.c \
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
BONUS=ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c
OBJS=$(SRCS:.c=.o)
BOBJS=$(BONUS:.c=.o)
NAME=libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(NAME) $(OBJS) $(BOBJS)
	ar -rcs $(NAME) $(OBJS) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
