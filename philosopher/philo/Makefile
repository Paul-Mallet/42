CC=cc
FLAGS=-Wall -Wextra -Werror -g -I includes/
T_FLAG=-pthread
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR), \
		main.c \
		parsing.c \
		print_data.c \
		handle_data.c \
		utils_conversion.c \
		utils_parsing.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
NAME=philo

all: $(NAME)
	@echo "philo compiled"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(T_FLAG) -o $@ $(OBJS)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "objs cleaned"

fclean : clean
	@rm -rf $(NAME)
	@echo "bin cleaned"

re: fclean all

.PHONY: all clean fclean re