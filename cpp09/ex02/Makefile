C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
NAME = PmergeMe
OBJCS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)

%.o: %.cpp PmergeMe.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean