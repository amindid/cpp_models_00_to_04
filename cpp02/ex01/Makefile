# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 15:27:46 by aouchaad          #+#    #+#              #
#    Updated: 2023/10/07 12:30:15 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp 
OBJS = ${SRCS:.cpp=.o}

NAME = Fixed

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${SRCS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all