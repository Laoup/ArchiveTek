##
## Makefile for my_select in /home/meuric_a/Project/my_select/V5.0_NORME
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Jan 10 22:03:15 2015 alban meurice
## Last update Sun Jan 11 22:52:03 2015 alban meurice
##

NAME	=	my_select

LIBNAME	=	libmy.a

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-pedantic

LDFLAGS	=	

AR	=	ar rc

RAN	=	ranlib

SRC	=	src/main.c \
		src/func_in_list.c \
		src/linked_list.c \
		src/linked_list2.c \
		src/position.c \
		src/position_move.c \
		src/func_term.c \
		src/func_term_ligne.c \
		src/supr_elem_list.c \
		src/my_getenv.c \
		src/signal.c \
		src/cmd.c \
		src/end.c \

LIB	=	lib/my_putchar.c \
		lib/my_putnbr.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/my_putchar_error.c \
		lib/my_puterror.c \

OBJ	=	$(SRC:.c=.o)

LIBOBJ	=	$(LIB:.c=.o)

CC	=	gcc -o

all	:	$(NAME)

$(NAME)	:	$(LIBOBJ) $(OBJ)
		$(AR) $(LIBNAME) $(LIBOBJ)
		$(RAN) $(LIBNAME)
		$(CC) $(LDFLAGS) $(NAME) $(SRC) $(LIBNAME) -lncurses

clean	:	
		rm -f $(OBJ) $(LIBOBJ)

fclean	:	clean
		rm -f $(NAME) $(LIBNAME)

re	:	fclean all

.PHONY	:	all clean fclean re
