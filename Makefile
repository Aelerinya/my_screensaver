##
## EPITECH PROJECT, 2018
## my_screensaver
## File description:
## Makefile fir the my_screensaver project
##

MAIN = src/main.c
OBJ = $(notdir $(MAIN:.c=.o))

NAME = my_screensaver

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

$(OBJ):
	gcc -c $(MAIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
