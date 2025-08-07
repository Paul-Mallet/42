CPP=c++
CFLAGS=-Wall -Wextra -Werror -g
CPPFLAGS=-std=c++98
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
			main.cpp)
OBJS_DIR=obj/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
NAME=hithisisbrain

all: $(NAME)
	@echo "\033[1;32m✔ hithisisbrain compiled"

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all clean fclean re