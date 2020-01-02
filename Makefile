##
## EPITECH PROJECT, 2020
## PSU_My_ls_2020
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	EXEC

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#gcc -o $(NAME) $(SRC_UT) tests/test_project.c -I./include -L./lib -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re
