C++ = c++
FLAGS = -std=c++98
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
NAME = human
OBJCS = $(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)
%.o: %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	$(C++) $(FLAGS) -c $< -o $@ 
clean:
	rm -f $(OBJCS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean