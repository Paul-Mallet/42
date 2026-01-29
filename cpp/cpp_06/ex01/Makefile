NAME=serializer
CPP=c++
FLAGS=-Wall -Wextra -Werror -std=c++98 -g
INCLUDES=-I includes/

OBJS_DIR=objs/
SRC_DIR=src/
DOC_DIR=doc/
TEST_DIR=tests/

MAIN=src/main.cpp
MAIN_OBJ=$(OBJS_DIR)main.o

FILES=Serializer

OBJS=$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
SRC=$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

TEST_FILES=test_Serializer
TEST=$(addprefix $(TEST_DIR), $(addsuffix .cpp, $(TEST_FILES)))
TEST_EXEC=./tests/tester_$(NAME)

VALID=\033[1;32m

all: $(NAME)

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^
	echo "$(VALID)✔ $(NAME) compiled"

$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(dir $@)
	$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

docs:
	doxygen Doxyfile
	echo "$(VALID)documentation compiled"

test:
	$(CPP) $(FLAGS) $(INCLUDES) $(SRC) $(TEST) -o $(TEST_EXEC)
	$(TEST_EXEC) -s

debug:
	gdb -tui $(NAME)

clean:
	rm -rf $(DOC_DIR)
	rm -rf $(OBJS_DIR)
	echo "documentation and objects files cleaned"

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_EXEC)
	echo "executive files cleaned"

re: fclean all

.PHONY: all docs test debug clean fclean re
.SILENT:
.DELETE_ON_ERROR: