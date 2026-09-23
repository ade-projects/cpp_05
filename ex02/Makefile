# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeestev <adeestev@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/19 13:16:06 by adeestev          #+#    #+#              #
#    Updated: 2026/09/23 15:28:15 by adeestev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = forms

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(NAME) has been successfully compiled"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@echo "object files have been deleted"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) has been deleted"

re: fclean all

.PHONY: all clean fclean re
