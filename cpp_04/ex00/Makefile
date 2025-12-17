CPP=c++
CFLAGS=-Wall -Wextra -Werror -g -std=c++98
INCLUDES=-I includes/
SRCSDIR=src/
SRCS=$(addprefix $(SRCSDIR),\
		main.cpp)
OBJSDIR=obj/
OBJS=$(patsubst $(SRCSDIR)%.cpp, $(OBJSDIR)%.o, $(SRCS))
NAME=polymorphism

all: $(NAME)
	@echo "\033[1;32m✔ Polymorphism compiled"

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(INCLUDES) -o $@ $^

$(OBJSDIR)%.o: $(SRCSDIR)%.cpp
	@mkdir $(dir $@)
	@$(CPP) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: $(OBJSDIR)
	@rm -rf $(OBJSDIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all clean fclean re