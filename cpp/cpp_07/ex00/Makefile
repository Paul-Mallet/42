CPP=c++
FLAGS=-Wall -Wextra -Werror -g -std=c++98 #c++14 for gtest, catch2 v.1.x.x instead
T_FLAGS=-lgtest -lgtest_main -pthread
INCLUDES=-I ./includes
OBJS_DIR=obj/
SRC_DIR=src/
TEST_DIR=tests/
FILES=main
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
TESTS=$(addprefix $(SRC_DIR), $(addprefix $(TEST_DIR), $(addprefix test_, $(addsuffix .cpp, $(FILES)))))
TEST_NAME=unit_test
DOC=doc/
VALID=\033[1;32m
INFOS=\033[0;33m
NAME=func_template

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) $(INCLUDES) -o $@ $^
	@echo "$(VALID)$(NAME) compilation succeed !"

$(OBJS_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(FLAGS) $(INCLUDES) -c $< -o $@

# test: $(OBJS)
# 	@$(CPP) -std=c++14 $(FLAGS) $(INCLUDES) $(TESTS) $^ -o $(TEST_NAME) $(T_FLAGS)
# 	@echo "$(VALID)Tests compilation is running..."
# 	@./$(TEST_NAME)

doc:
	@doxygen Doxyfile
	@echo "$(VALID)Documentation compilation succeed !"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(INFOS) object files cleaned."

fclean: clean
	@rm -rf $(DOC)
	@rm -f $(NAME)
	@echo "$(INFOS) documentation & executive cleaned."

re: fclean all

.PHONY: all test doc clean fclean re