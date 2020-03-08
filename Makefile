NAME = test1
FLAGS = -Wall -Wextra -Werror
SRC = *.c
OBJ = *.o

ALL:
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean :
	/bin/rm -f $(OBJ)
