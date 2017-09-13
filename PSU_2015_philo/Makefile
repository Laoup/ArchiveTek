##
## Makefile for my_select in /home/meuric_a/Project/my_select/V5.0_NORME
##
## Made by alban meurice
## Login   <meuric_a@epitech.net>
##
## Started on  Sat Jan 10 22:03:15 2015 alban meurice
## Last update Sun Mar 13 17:08:45 2016 Alban Meurice
##

NAME	=	philo

CFLAGS	+=	-W -Wextra -Wall -Werror
CFLAGS	+=	-g3
CFLAGS	+=	-I ./include

LDFLAGS	+=	-Wl,-rpath=. -L. -lriceferee -lpthread

SRC	=	src/main.c \
		src/check.c \
		src/func.c \
		src/philo.c \
		src/func_list.c \

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -o

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
