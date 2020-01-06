##
## EPITECH PROJECT, 2020
## PSU_My_ls_2020
## File description:
## Project makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c			\
		$(DSRC)constant_macro.c	\
		$(DSRC)browse_folders.c	\
		$(DSRC)browse_folder.c	\
		$(DSRC)display/display_file_data.c	\
		$(DSRC)display/display_file_data_type_right.c	\
		$(DSRC)display/display_file_data_owner.c	\
		$(DSRC)display/display_file_data_size.c	\
		$(DSRC)display/display_file_data_time.c	\
		$(DSRC)get_argument.c	\
		$(DSRC)config_destroy.c	\
		$(DSRC)get_files.c		\
		$(DSRC)sort_files.c		\
		$(DSRC)sort_path.c		\
		$(DSRC)tools.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

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
