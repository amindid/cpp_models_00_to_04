CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = PhoneBook.cpp Contact.cpp main.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = MyPhoneBook

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} main.cpp -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all