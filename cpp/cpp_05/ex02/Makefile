CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
INCLUDES=-I includes/
OBJS_DIR=objs/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		main.cpp)
DOCS_DIR=docs/
NAME=bureaucrat

all: $(NAME)
	@echo "\033[1;32m✔ bureaucrat compiled"

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

docs:
	@doxygen Doxyfile
	@echo "\033[1;32mDocumentation generated"

clean:
	@rm -rf $(DOCS_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mdocs & objs cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all docs clean fclean re