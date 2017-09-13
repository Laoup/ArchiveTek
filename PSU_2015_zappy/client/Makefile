##
## Makefile for Makefile in /home/masson_q/rendu/PSU_2015_zappy/src
## 
## Made by masson mathieu
## Login   <masson_q@epitech.net>
## 
## Started on  Mon Jun 13 15:33:57 2016 masson mathieu
## Last update Fri Jun 24 23:48:35 2016 Jaime Dossantos
##

CC	=	gcc

RM	=	rm -f

SRC	=	main.c \
		socket.c \
		manager.c \
		trantor.c \
		inventaire.c \
		init_trantor.c \
		prend.c \
		tabf.c \
		elevation.c \
		fonctions1.c \
		fonctions2.c \
		ia.c \

NAME	=	zappy

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
