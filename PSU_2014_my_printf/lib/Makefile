##
## Makefile for Project my_printf.c in /home/meuric_a/PSU_2014_my_printf/lib
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Nov 15 01:23:39 2014 alban meurice
## Last update Sat Nov 15 01:56:05 2014 alban meurice
##

MY	=	my_printf.h

AR	=	ar rc

NAME	=	libmy.a

RAN	=	ranlib

SRC	=	my_printf.c \
		my_flags.c \
		my_flags2.c \
		my_put_nbr_bin.c \
		my_put_nbr_hexa.c \
		my_put_nbr_octal.c \
		my_putchar.c \
		my_put_nbr.c \
		my_putstr.c \

OBJ	=	$(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(NAME) $(OBJ) my_printf.h
		$(RAN) $(NAME)
		cp $(NAME) ../

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re	: fclean all

.PHONY	: all clean fclean re
