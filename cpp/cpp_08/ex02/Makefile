NAME=mutant_stack
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98 -g
INCLUDES=-I ./includes

OBJ_DIR=obj/
SRC_DIR=src/
DOC_DIR=doc/
TEST_DIR=tests/

SRC_FILES=main MutantStack

SRC=$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ=$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

TEST_FILES=MutantStack
TESTS=$(addprefix $(TEST_DIR)test_, $(addsuffix .cpp, $(TEST_FILES)))
TEST_NAME=tester_$(NAME)

VALID=\033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(INCLUDES) $^ -o $@
	echo "$(VALID)$(NAME) built"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(dir $(OBJ_DIR))
	$(CPP) $(FLAGS) $(INCLUDES) -c $^ -o $@

doc:
	doxygen Doxyfile
	echo "$(VALID)doc generated"

test:
	$(CPP) $(FLAGS) $(INCLUDES) $(TESTS) -o $(TEST_DIR)$(TEST_NAME)
	./$(TEST_DIR)$(TEST_NAME) -s

debug:
	gdb -tui $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	echo "obj cleaned"
	rm -rf $(DOC_DIR)
	echo "doc cleaned"

fclean: clean
	rm -f $(NAME)
	echo "exec cleaned"
	rm -f $(TEST_NAME)
	echo "tester cleaned"

re: fclean all

.PHONY: all doc test debug clean fclean re
.SILENT:
.DELETE_ON_ERROR: