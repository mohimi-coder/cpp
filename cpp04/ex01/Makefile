C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Cat.cpp Dog.cpp Animal.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp
NAME = Brain
OBJCS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)

%.o: %.cpp Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean