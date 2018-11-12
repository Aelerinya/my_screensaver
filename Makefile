##
## EPITECH PROJECT, 2018
## my_screensaver
## File description:
## Makefile fir the my_screensaver project
##

MAIN = src/main.c
OBJ = $(notdir $(MAIN:.c=.o))

LIB = my
L_PATH = ./lib/my/
I_PATH = ./include/

NAME = my_screensaver

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(L_PATH) -l$(LIB)

$(OBJ):
	gcc -c $(MAIN) -I$(I_PATH)

lib:
	$(MAKE) -C $(L_PATH)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(L_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(L_PATH) fclean

re: fclean all

.PHONY: all lib clean fclean re
