CPP=c++
FLAGS=-Wall -Wextra -Werror -g -std=c++98
INCLUDES=-I includes/
OBJ_DIR=obj/
OBJ=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))
SRC_DIR=src/
SRC=$(addprefix $(SRC_DIR),\
		main.cpp)
DOC_DIR=doc/
VALID=\033[1;32m
INFO=\033[0;33m
NAME=type_casting

all: $(NAME)
	@echo "$(VALID)✔ type_casting compiled"

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

doc:
	@doxygen Doxyfile
	@echo "$(VALID)✔ documentation compiled"

clean:
	@rm -rf $(DOC_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(INFO)Documentation, objects and _shrubbery files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "$(INFO)Executive file cleaned"

re: fclean all

.PHONY: all doc clean fclean re