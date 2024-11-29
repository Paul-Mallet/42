CC= cc
CFLAGS= -Wall -Wextra -Werror
SRCS= get_next_line.c \
      get_next_line_utils.c
#SRCBS= get_next_line_bonus.c \
       get_next_line_utils_bonus.c
OBJS= $(SRCS:.c=.o)
#OBJBS= $(SRCBS:.c=.o)
NAME= libftgetnextline.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $@ $^

exec: $(NAME)
	$(CC) -L. $^ -o gnl

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
