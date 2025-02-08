C++ = c++
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -std=c++98
SRC = main.cpp whatever.cpp
NAME = whatever
OBJCS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)

%.o: %.cpp whatever.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean