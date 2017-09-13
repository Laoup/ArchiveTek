##
## Makefile for project My_ls in /home/meuric_a/PSU_2014_my_ls/lib
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Nov 29 03:58:51 2014 alban meurice
## Last update Sat Nov 29 04:36:04 2014 alban meurice
##

MY	=	my_ls_save6.h my_printf.h

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
		my_ls_save6.c

OBJ	=	$(SRC:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(NAME) $(OBJ) $(MY)
		$(RAN) $(NAME)
		cc my_ls_save6.c my_ls_save6.h $(NAME)
		mv a.out my_ls
		cp my_ls ../

clean	:
		rm -f $(OBJ)

fclean	: clean
		rm -f $(NAME) my_ls
		rm -f ../my_ls

re	: fclean all

.PHONY	: all clean fclean re
