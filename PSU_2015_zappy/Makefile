##
## Makefile for Tech1 in /home/dossan_a/bin
## 
## Made by Jaime Dossantos
## Login   <dossan_a@epitech.net>
## 
## Started on  Sat Dec 27 11:43:51 2014 Jaime Dossantos
## Last update Sun Jun 26 22:27:26 2016 Avel Docquin
##

SRC_S	= server/main.c \
	server/ressources.c \
	server/ressources_0.c \
	server/list.c \
	server/map.c \
	server/misc.c \
	server/select.c \
	server/parser/parse_order.c \
	server/parser/str_to_tab.c \
	server/send.c \
	server/send0.c \
	server/send1.c \
	server/execute.c \
	server/free.c \
	server/writing.c \
	server/time.c \
	server/connection.c

SRC_C	= client/main.c \
          client/socket.c \
          client/manager.c \
          client/trantor.c \
          client/inventaire.c \
          client/init_trantor.c \
          client/prend.c \
          client/tabf.c \
          client/elevation.c \
          client/fonctions1.c \
          client/fonctions2.c \
          client/ia.c \

OBJ_S	= $(SRC_S:.c=.o)

OBJ_C	= $(SRC_C:.c=.o)

SERVER	= zappy_server

CLIENT	= zappy_ai

RM	= rm -rf

CFLAGS	= -W -Wall -ansi -pedantic -g -g3 -O0 -Ofast -LSDL2

CC	= gcc

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ_S)
		$(CC) -o $(SERVER) $(OBJ_S) $(CFLAGS) -lSDL2 $(LIB)

$(CLIENT):	$(OBJ_C)
		$(CC) -o $(CLIENT) $(OBJ_C)  $(LIB)

clean:
		$(RM) $(OBJ_C) $(OBJ_S)
fclean:		clean
		$(RM) $(SERVER) $(CLIENT)

re:		fclean all

srun: re
	valgrind --track-origins=yes ./$(SERVER) -p 4242 -x 100 -y 100 -n "ok" "ad" -c 3 -t 1

.PHONY: all clean fclean re srun
