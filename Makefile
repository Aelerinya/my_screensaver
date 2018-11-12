##
## EPITECH PROJECT, 2018
## my_screensaver
## File description:
## Makefile fir the my_screensaver project
##

MAIN = src/main.c
SRC = 	src/errors.c \
	src/load_screensaver.c \
	src/framebuffer.c \
	src/screensavers/first_screensaver.c
OBJ = $(notdir $(MAIN:.c=.o)) $(notdir $(SRC:.c=.o))

CSFML = -lcsfml-graphics
LIB = my
L_PATH = ./lib/my/
I_PATH = ./include/

NAME = my_screensaver

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CSFML) $(OBJ) -L$(L_PATH) -l$(LIB) -Wall -Wextra -pedantic

$(OBJ):
	gcc -g3 -c $(MAIN) $(SRC) -I$(I_PATH) -Wall -Wextra -pedantic

lib:
	$(MAKE) -s -C $(L_PATH)

clean:
	rm -f $(OBJ)
	$(MAKE) -s -C $(L_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -s -C $(L_PATH) fclean

re: fclean all

.PHONY: all lib clean fclean re
