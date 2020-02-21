##
## EPITECH PROJECT, 2019
## MUL_my_hunter_2019
## File description:
## Makefile
##

SRC	=	window.c	\
		vector.c	\
		cursor.c	\
		rect.c	\
		text.c

OBJ	=	$(SRC:.c=.o)

NAME = libmy_graph.a

HEADER = my_graph.h

CFLAGS += -W -Wall -Wextra -pedantic -l csfml-system -l csfml-graphics -l csfml-window

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../
	mkdir -p ../../include
	cp $(HEADER) ../../include
	rm -f $(OBJ)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(NAME)