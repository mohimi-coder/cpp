C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Contact.cpp PhoneBook.cpp main.cpp
OBJS= $(SRC:.cpp=.o)
NAME = Phonebook

all: $(NAME)

$(NAME): $(OBJS)
		$(C++) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp Contact.hpp PhoneBook.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all