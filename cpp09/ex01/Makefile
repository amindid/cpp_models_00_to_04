# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:27:46 by aouchaad          #+#    #+#              #
#    Updated: 2023/12/12 11:08:18 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp RPN.cpp
OBJS = ${SRCS:.cpp=.o}

NAME = RPN

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CXXFLAGS} ${OBJS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all