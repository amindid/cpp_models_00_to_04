# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 18:22:52 by aouchaad          #+#    #+#              #
#    Updated: 2023/09/30 18:22:54 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PhoneBook.cpp Contact.cpp 
OBJS = ${SRCS:.cpp=.o}

NAME = MyPhoneBook

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${SRCS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all