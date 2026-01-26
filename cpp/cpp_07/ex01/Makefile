NAME=iter
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98 -g
INCLUDES=-I ./includes

OBJ_DIR=objs/
SRC_DIR=src/
DOC_DIR=doc/
TEST_DIR=tests/

FILES=main

OBJS=$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRC=$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

TEST_FILES=test_main test_iter
TEST=$(addprefix $(TEST_DIR), $(addsuffix .cpp, $(TEST_FILES)))
TEST_EXEC=./test_$(NAME)

VALID=\033[0;32m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^
	@echo "$(VALID)exec compiled as: $(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(VALID)objs compiled"

doc:
	@doxygen Doxyfile
	@echo "$(VALID)doc generated"

test: $(TEST)
	@$(CPP) $(FLAGS) $(INCLUDES) $(TEST) -o $(TEST_EXEC)
	@$(TEST_EXEC) || (echo "$(RED)Tests failed!$(RESET)" && exit 0)

debug:
	@gdb $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "objs cleaned"

fclean: clean
	@rm -rf $(DOC_DIR)
	@echo "doc cleaned"
	@rm -f $(TEST_EXEC)
	@echo "test cleaned"
	@rm -f $(NAME)
	@echo "exec cleaned"

re: fclean all

.PHONY: all doc test debug clean fclean re