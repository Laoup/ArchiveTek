##
## Makefile for project My_ls in /home/meuric_a/PSU_2014_my_ls/lib
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Nov 29 03:58:51 2014 alban meurice
## Last update Sat Nov 29 04:48:58 2014 alban meurice
##

MY	=	lib/my_ls_save6.h lib/my_printf.h

AR	=	ar rc

NAME	=	libmy.a

RAN	=	ranlib

SRC	=	lib/my_printf.c \
		lib/my_flags.c \
		lib/my_flags2.c \
		lib/my_put_nbr_bin.c \
		lib/my_put_nbr_hexa.c \
		lib/my_put_nbr_octal.c \
		lib/my_putchar.c \
		lib/my_put_nbr.c \
		lib/my_putstr.c \
		lib/my_ls_save6.c

OBJ	=	$(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(NAME) $(OBJ) $(MY)
		$(RAN) $(NAME)
		cc lib/my_ls_save6.c lib/my_ls_save6.h $(NAME)
		mv a.out my_ls
		cp my_ls ../

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME) my_ls
		rm -f ../my_ls

re	: fclean all

.PHONY	: all clean fclean re
