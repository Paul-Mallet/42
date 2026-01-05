CPP=c++
CFLAGS=-Wall -Wextra -Werror -g -std=c++98
INCLUDES=-I includes/
SRCSDIR=src/
SRCS=$(addprefix $(SRCSDIR),\
		Animal.cpp\
		Cat.cpp\
		Dog.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		main.cpp)
OBJSDIR=obj/
OBJS=$(patsubst $(SRCSDIR)%.cpp, $(OBJSDIR)%.o, $(SRCS))
DOCDIR=doc/
NAME=polymorphism

all: $(NAME)
	@echo "\033[1;32m✔ polymorphism compiled"

$(NAME): $(OBJS)
	@$(CPP) $(CFLAGS) $(INCLUDES) -o $@ $^

$(OBJSDIR)%.o: $(SRCSDIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CFLAGS) $(INCLUDES) -c $< -o $@

doc:
	@doxygen Doxyfile
	@echo "\033[1;32m✔ Documentation generated"

clean:
	@rm -rf $(OBJSDIR)
	@rm -rf $(DOCDIR)
	@echo "\033[0;33mobjs cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;33mbin cleaned"

re: fclean all

.PHONY: all doc clean fclean re