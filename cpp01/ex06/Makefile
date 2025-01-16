C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Harl.cpp
NAME = harlFilter
OBJCS = $(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)
%.o: %.cpp Harl.hpp
	$(C++) $(FLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean