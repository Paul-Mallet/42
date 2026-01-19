CPP=c++
FLAGS=-Wall -Wextra -Werror -g -std=c++98
INCLUDES=-I includes/
OBJS_DIR=objs/
OBJS=$(patsubst $(SRCS_DIR)%.cpp, $(OBJS_DIR)%.o, $(SRCS))
SRCS_DIR=src/
SRCS=$(addprefix $(SRCS_DIR),\
		Serializer.cpp\
		main.cpp)
DOCS_DIR=docs/
VALID=\033[1;32m
INFO=\033[0;33m
NAME=serialize

all: $(NAME)
	@echo "$(VALID)✔ serialize compiled"

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

docs:
	@doxygen Doxyfile
	@echo "$(VALID)documentation compiled"

clean:
	@rm -rf $(DOCS_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(SHRUB_FILES)
	@echo "$(INFO)documentation and objects files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "$(INFO)executive file cleaned"

re: fclean all

.PHONY: all docs clean fclean re