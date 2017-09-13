##
## Makefile for Makefile in /home/guzman_y/rendu/Piscine_C_J11
##
## Made by yoann guzman
## Login   <guzman_y@epitech.net>
##
## Started on  Mon Oct 20 14:22:15 2014 yoann guzman
## Last update Sun Apr 12 21:34:51 2015 Moisset Raphael
##

RM	=	rm -f

HEAD	=	my.h

CFLAGS	+=	-Wextra -Wall -Werror
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I../include

NAME	=	libmy$(HOSTTYPE).a

LIB	=	ar rc

SRCS	=	my_putchar.c \
		my_putstr.c \
		my_put_nbr.c \
		my_strlen.c \
		my_getnbr.c \
		my_strdup.c \
		my_putnbr_base.c \
		my_strcpy.c \
		my_strcat.c \
		my_strncmp.c \
		my_get_env.c \
		get_next_line.c \
		my_str_to_world_tab.c \
		my_atoi_base.c \
		my_strcmp.c \
		my_epur_str.c

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(LIB) $(NAME) $(OBJS)
		ranlib $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
