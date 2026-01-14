CC=cc
FLAGS=-Wall -Wextra -Werror -g -I includes/
T_FLAG=-pthread #-fsanitize=thread
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR), \
		main.c \
		parsing.c \
		init.c \
		handling.c \
		dinner.c \
		routines.c \
		subroutines.c \
		clean.c \
		print.c \
		errors.c \
		utils_conversion.c \
		utils_parsing.c \
		utils_routine.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
VALID=\033[1;32m
INFO=\033[0;33m
NAME=philo

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -rdynamic -Xlinker -export-dynamic $(FLAGS) $(T_FLAG) -o $@ $(OBJS)
	@echo "$(VALID)philo compiled"

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(T_FLAG) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(INFO)objs cleaned"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(INFO)bin cleaned"

re: fclean all

.PHONY: all clean fclean re