# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:27:46 by aouchaad          #+#    #+#              #
#    Updated: 2023/12/12 11:03:44 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp
OBJS = ${SRCS:.cpp=.o}

NAME = PmergeMe

		
all : ${NAME}
	
${NAME} : ${OBJS} PmergeMe.hpp
		${CC} ${CXXFLAGS} ${OBJS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all