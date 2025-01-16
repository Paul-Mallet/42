CC= gcc
CFLAGS= -Wall -Wextra -Werror
SRC= main.c \
     hooks.c \
     utils.c
OBJ= $(SRC:.c=.o)
NAME= fractol

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -g -c $< -o $@ #-O3

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -lXext -lX11 -o $(NAME) #-L/usr/lib -Iminilibx-linux -lm -lz

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
