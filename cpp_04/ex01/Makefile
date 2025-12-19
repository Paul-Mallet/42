CPP=c++
FLAGS=-Wall -Wextra -Werror -g -std=c++98
INCLUDES=-I includes/
SRC_DIR=src/
SRCS=$(addprefix $(SRC_DIR),\
		Brain.cpp\
		Animal.cpp\
		Cat.cpp\
		Dog.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		main.cpp)
OBJ_DIR=obj/
OBJS=$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRCS))
DOC_DIR=doc/
NAME=brain

all: $(NAME)
	@echo "\033[1;32m✔ brain compiled"

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

doc:
	@doxygen Doxyfile
	@echo "Documentation generated"

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DOC_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all doc clean fclean re