C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp BitcoinExchange.cpp
NAME = btc
OBJCS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)

%.o: %.cpp BitcoinExchange.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean