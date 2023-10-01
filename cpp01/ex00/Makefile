# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:22:06 by aouchaad          #+#    #+#              #
#    Updated: 2023/10/01 13:48:55 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp 
OBJS = ${SRCS:.cpp=.o}

NAME = Zombie

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${SRCS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all