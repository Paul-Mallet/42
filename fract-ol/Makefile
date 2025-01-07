CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRC= main.c \
     hooks.c \
     utils.c
OBJ= $(SRC:.c=.o)
NAME= fractol

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -O3 -g -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
