C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Serializer.cpp Data.cpp
NAME = serilizer
OBJCS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)

%.o: %.cpp Serializer.hpp Data.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean