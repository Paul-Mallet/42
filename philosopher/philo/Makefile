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
NAME=philo

all: $(NAME)
	@echo "philo compiled"

$(NAME): $(OBJS)
	@$(CC) -rdynamic -Xlinker -export-dynamic $(FLAGS) $(T_FLAG) -o $@ $(OBJS)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(T_FLAG) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "objs cleaned"

fclean : clean
	@rm -rf $(NAME)
	@echo "bin cleaned"

re: fclean all

.PHONY: all clean fclean re