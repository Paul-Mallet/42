CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRC= main.c \
	 init.c \
     hooks.c \
	 render.c \
     utils1.c \
	 utils2.c
OBJ= $(SRC:.c=.o)
NAME= fractol

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -g -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
