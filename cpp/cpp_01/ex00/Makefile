CPP=c++
CFLAGS=-Wall -Wextra -Werror -g
CPPFLAGS=-std=c++98
HEADERS=-I includes/
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
			Zombie.cpp\
			newZombie.cpp\
			randomChump.cpp\
			main.cpp)
OBJS_DIR=obj/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
NAME=braiiiiiiiinnnzzzz

all: $(NAME)
	@echo "\033[1;32m✔ braiiiiiiiinnnzzzz compiled"

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) $(HEADERS) -o $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all clean fclean re