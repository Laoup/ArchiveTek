##
## Makefile for my_select in /home/meuric_a/Project/my_select/V5.0_NORME
## 
## Made by alban meurice
## Login   <meuric_a@epitech.net>
## 
## Started on  Sat Jan 10 22:03:15 2015 alban meurice
## Last update Thu Jun 30 11:10:49 2016 Alban Meurice
##

NAME	=	autocompletion

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-g3
CFLAGS	+=	-I include

LDFLAGS	=

SRC	=	src/main.cpp \

OBJ	=	$(SRC:.c=.o)

CC	=	g++ -o

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(LDFLAGS) $(NAME) $(OBJ)

clean	:	
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
