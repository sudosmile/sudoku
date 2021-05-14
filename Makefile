SRC_FILE	=	main

SRC 		= 	$(addsuffix .c, $(addprefix src/, $(SRC_FILE)))

OBJ		=	$(SRC:.c=.o)

NAME		=	sudokusmile

CFLAGS		=	-W -Wall -Wextra -g3

CPPFLAGS	=	-I./include

CC		=	gcc

all:		$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
