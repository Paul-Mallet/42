NAME=ircserv
TEST_NAME=tester_ircserv

CPP=c++
FLAGS=-Wall -Wextra -Werror -g
CPPSTD=-std=c++98
INCLUDES=-I ./includes

SRC_DIR=src/
OBJ_DIR=obj/
DOC_DIR=doc/
TEST_DIR=test/

FILES=main Server Client Channel

SRC_FILES=$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
OBJ_FILES=$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
TEST_FILES=$(addprefix $(TEST_DIR)test_, $(addsuffix .cpp, $(FILES)))

VALID=/033[0;32m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CPP) $(FLAGS) $(CPPSTD) $(INCLUDES) $^ -o $@
	echo "$(NAME) compiled"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(dir $(OBJ_DIR))
	$(CPP) $(FLAGS) $(CPPSTD) $(INCLUDES) -c $^ -o $@

debug:
	gdb -tui $(NAME)

test:
	$(CPP) $(FLAGS) $(CPPSTD) $(INCLUDES) $^ -o $(TEST_DIR)$(TEST_NAME)
	./$(TEST_DIR)$(TEST_NAME) -s

doc:
	doxygen Doxyfile
	echo "doc file built"

clean:
	rm -rf $(OBJ_DIR)
	echo "obj/ removed"
	rm -rf $(DOC_DIR)
	echo "doc/ removed"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) removed"

re: fclean all

.PHONY: all debug doc test clean fclean re
.SILENT:
.DELETE_ON_ERROR: