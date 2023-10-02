# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aouchaad <aouchaad@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 13:35:01 by aouchaad          #+#    #+#              #
#    Updated: 2023/10/02 20:50:46 by aouchaad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = ${SRCS:.cpp=.o}

NAME = SedIsForLosers

		
all : ${NAME}

${NAME} : ${OBJS}
		${CC} ${CFLAGS} ${SRCS} -o $@

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		
re : fclean all

tests : all
#file exist and valid arguments
	@echo "\n\t<><><><>< test 1 ><><><><>"
	@echo "<><><><>< normal case ><><><><>"
	./${NAME} Makefile " " "_" || true
#file exist and invalid arguments
	@echo "\n\t<><><><>< test 2 ><><><><>"
	@echo "<><><><>< invalid arguments ><><><><>"
	./${NAME} Makefile "" " " || true
#file dont exist
	@echo "\n\t<><><><>< test 3 ><><><><>"
	@echo "<><><><>< file dont exist ><><><><>"
	./${NAME} file "hello" "HELLO" || true
#file exist but with no read permission
	@echo "\n\t<><><><>< test 4 ><><><><>"
	@echo "<><><><>< no read permission ><><><><>"
	touch file_cant_be_read
	chmod -r file_cant_be_read
	./${NAME} file_cant_be_read "hello" "HELLO" || true
#empty file
	@echo "\n\t<><><><>< test 5 ><><><><>"
	@echo "<><><><>< empty file ><><><><>"
	touch empty_file
	./${NAME} empty_file "hello" "HELLO" || true
#word not found
	@echo "\n\t<><><><>< test 6 ><><><><>"
	@echo "<><><><>< word not found ><><><><>"
	./${NAME} main.cpp "hello" "i found it" || true
	diff main.cpp main.cpp.replace
#file contain only the to_be_replaced word
	@echo "\n\t<><><><>< test 7 ><><><><>"
	@echo "<><><><>< file contain only the to_be_replaced word ><><><><>"
	touch one_word
	echo hello >one_word
	./${NAME} one_word "hello" "yeah it works" || true

tmpclean : fclean
	rm -f empty_file
	rm -f empty_file.replace
	rm -f file_cant_be_read
	rm -f main.cpp.replace
	rm -f Makefile.replace
	rm -f one_word
	rm -f one_word.replace

.PHONY: tests re all clean fclean tmpclean


	