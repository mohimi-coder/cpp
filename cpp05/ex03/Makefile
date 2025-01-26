C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
	 RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
NAME = aform
OBJCS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJCS)
		$(C++) $(FLAGS) -o $(NAME) $(OBJCS)

%.o: %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
	$(C++) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean