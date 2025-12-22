CPP=c++
FLAGS=-Wall -Wextra -Werror -g -std=c++98
INCLUDES=-I includes/
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
		AAnimal.cpp\
		Cat.cpp\
		Dog.cpp\
		Brain.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		main.cpp)
OBJS_DIR=obj/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
DOC_DIR=doc/
NAME=abstract

all: $(NAME)
	@echo "\033[1;32m✔ abstract compiled"

doc:
	@doxygen Doxyfile
	@echo "Documentation generated"

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) $^ -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(DOC_DIR)
	@rm -f $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all doc clean fclean re