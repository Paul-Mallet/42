CC=cc
FLAGS=-Wall -Wextra -Werror -g -I includes/
T_FLAG=-pthread
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR), \
		main.c \
		parsing.c \
		init.c \
		handling.c \
		routines.c \
		errors.c \
		clean.c \
		print.c \
		utils_conversion.c \
		utils_parsing.c \
		utils_routine.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
NAME=philo

all: $(NAME)
	@echo "philo compiled"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $@ $(OBJS) # $(T_FLAG)

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