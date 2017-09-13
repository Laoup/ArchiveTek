##
## Makefile for my_select in /home/meuric_a/Project/my_select/V5.0_NORME
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Jan 10 22:03:15 2015 alban meurice
## Last update Fri Mar 20 19:42:59 2015 Alban Meurice
##

NAME	=	client/client

NAME2	=	server/server

LIBNAME	=	libmy.a

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-I include

LDFLAGS	=

AR	=	ar rc

RAN	=	ranlib

SRC	=	client/src/main.c \
		client/src/func_pars.c \
		client/src/my_conv_bin.c

SRC_SER	=	server/src/main.c \
		server/src/conv_dec.c

LIB	=	lib/my_putchar.c \
		lib/my_putnbr.c \
		lib/my_putstr.c \
		lib/my_strlen.c \
		lib/my_putchar_error.c \
		lib/my_puterror.c \
		lib/my_getnbr.c \
		lib/my_memset.c \
		lib/my_str_to_word_tab.c \
		lib/ver_malloc.c \
		lib/my_epurstr.c \
		lib/my_strcmp.c \
		lib/my_strdup.c \
		lib/my_strcat.c \
		lib/my_strcmp_spe.c \

OBJ	=	$(SRC:.c=.o)

OBJ_SER	=	$(SRC_SER:.c=.o)

LIBOBJ	=	$(LIB:.c=.o)

CC	=	gcc -o

all	:	$(NAME) $(NAME2)

$(NAME)	:	$(LIBOBJ) $(OBJ)
		$(AR) $(LIBNAME) $(LIBOBJ)
		$(RAN) $(LIBNAME)
		$(CC) $(LDFLAGS) $(NAME) $(OBJ) $(LIBNAME)

$(NAME2):	$(OBJ_SER)
		$(CC) $(LDFLAGS) $(NAME2) $(OBJ_SER) $(LIBNAME)

clean	:	
		rm -f $(OBJ) $(OBJ_SER) $(LIBOBJ)

fclean	:	clean
		rm -f $(NAME) $(NAME2) $(LIBNAME)

re	:	fclean all

.PHONY	:	all clean fclean re
