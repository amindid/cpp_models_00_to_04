# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:27:46 by aouchaad          #+#    #+#              #
#    Updated: 2023/11/01 13:22:17 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = ${SRCS:.cpp=.o}

NAME = Bureaucrat

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		rm -f *_shrubbery

re : fclean all