CPP=c++
C_FLAGS=-Wall -Wextra -Werror -g
CPP_FLAG=-std=c++98
HEADER_FLAG=-I includes/
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR), \
		Phonebook.class.cpp\
		Contact.class.cpp\
		utils.cpp\
		main.cpp)
OBJS_DIR=obj/
OBJS=$(SRCS:%.cpp=$(OBJS_DIR)%.o)
NAME=phonebook

all: $(NAME)
	@echo "\033[1;32m✔ phonebook compiled"

$(NAME): $(OBJS)
	@$(CPP) $(C_FLAGS) $(HEADER_FLAG) $(CPP_FLAG) -o $@ $(OBJS)

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(C_FLAGS) $(HEADER_FLAG) $(CPP_FLAG) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all clean fclean re