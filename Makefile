NAME = Calculax

SRC =   src/main.c \
		src/utils.c \
		src/interpreter.c \
		src/calculator.c \
		src/memory.c \
		src/history.c \
		src/actions.c \
		src/split_line.c

OBJ =		$(SRC:.c=.o)

all :		$(NAME)

$(NAME):	$(OBJ)
			gcc -g3 -Wall -Wextra -pedantic -o $(NAME) $(OBJ) -lncurses

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			echo_name fclean all

.PHONY:		echo_name all clean fclean re