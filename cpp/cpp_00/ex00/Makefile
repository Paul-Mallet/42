CPP=c++
C_FLAGS=-Wall -Wextra -Werror -g
CPP_FLAG=-std=c++98
SRC_DIR=src/
SRC=$(addprefix $(SRC_DIR), megaphone.cpp)
OBJS_DIR=obj/
OBJS=$(SRC:$(SRC_DIR)%.cpp=$(OBJS_DIR)%.o)
NAME=megaphone

all: $(NAME)
	@echo "\033[1;32m✔ megaphone compiled"

$(NAME): $(OBJS)
	@$(CPP) $(C_FLAGS) $(CPP_FLAG) -o $@ $(OBJS)

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(C_FLAGS) $(CPP_FLAG) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all clean fclean re