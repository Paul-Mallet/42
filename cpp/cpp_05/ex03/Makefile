CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
INCLUDES=-I includes/
OBJS_DIR=objs/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
		Bureaucrat.cpp\
		Intern.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp\
		main.cpp)
DOCS_DIR=docs/
SHRUB_FILES=$(shell ls | grep "_shrubbery")
GREEN=\033[1;32m
YELLOW=\033[0;33m
RED=\033[0;31m
NAME=bureaucrat

all: $(NAME)
	@echo "$(GREEN)✔ bureaucrat compiled"

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

docs:
	@doxygen Doxyfile
	@echo "$(GREEN)Documentation generated"

clean:
	@rm -rf $(DOCS_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(SHRUB_FILES)
	@echo "$(YELLOW)Documentation, objects and _shrubbery files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)Executive file cleaned"

re: fclean all

.PHONY: all docs clean fclean re