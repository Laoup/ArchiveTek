##
## Makefile for my_select in /home/meuric_a/Project/my_select/V5.0_NORME
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Jan 10 22:03:15 2015 alban meurice
## Last update Sun May 15 23:19:13 2016 Alban Meurice
##

NAME	=	server

LIBNAME	=	libmy.a

#CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-g3
CFLAGS	+=	-I inc

LDFLAGS	=

SRC	=	src/main.c \
		src/server.c \
		src/cmd_func.c \
		src/handle_func.c \
		src/handle_func2.c \
		src/handle_func3.c \
		src/handle_func4.c \
		src/data_socket.c \
		src/func_file.c \
		src/my_epurstr.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(NAME) $(OBJ)

clean	:	
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
