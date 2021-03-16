##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -W -Wall -Wextra -g -o $(NAME) $(SRC) -L./lib/my -lmy -lncurses

clean:
	make clean -C ./lib/my
	rm -f *~
	rm -f *#

fclean: clean
	make fclean -C ./lib/my
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my

bonus: all
	make -C ./.bonus