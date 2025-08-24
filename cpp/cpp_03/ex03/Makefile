CPP=c++
CFLAGS=-Wall -Wextra -Werror -g
CPPFLAGS=-std=c++98
INCLUDES=-I includes/
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
			ClapTrap.cpp\
			ScavTrap.cpp\
			FragTrap.cpp\
			DiamondTrap.cpp\
			main.cpp)
OBJS_DIR=obj/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
NAME=DiamondTrap

all: $(NAME)
	@echo "\033[1;32m✔ DiamondTrap compiled"

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

clean: $(OBJS_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all clean fclean re