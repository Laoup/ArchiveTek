##
## Makefile for lem-in in /home/jallut_p/git_repos/Piscine/CPE_2014_lemin
## 
## Made by pierre jallut
## Login   <jallut_p@epitech.net>
## 
## Started on  Fri Apr 17 18:22:34 2015 pierre jallut
## Last update Sun May  3 23:02:45 2015 pierre jallut
##

NAME	= lem_in

RM	= rm -f

CC	= cc

SRC	= src/nest_init/init/init.c \
	src/nest_init/utils/pile_ops.c \
	src/nest_init/utils/utils.c \
	src/nest_init/utils/print.c \
	src/nest_init/init/tubes.c \
	src/graphic/init/graph_init.c \
	src/graphic/misc/misc.c \
	src/graphic/utils/utils.c \
	src/graphic/utils/print.c \
	src/parser/init_func.c \
	src/parser/parsing.c \
	src/parser/get_file.c \
	src/parser/func_2d_tab.c \
	src/parser/check_func.c \
	src/parser/fill_the_struct.c \
	src/parser/func_fill.c \
	src/parser/fill_tab_name.c \
	src/parser/fill_tab_name2.c \
	src/parser/fill_tab_name_start.c \
	src/parser/fill_tab_name_end.c \
	src/parser/get_tube.c \
	src/parser/get_tube2.c \
	src/parser/search_func.c \
	src/parser/func_for_graphpart.c \
	src/pathfinding/cover_paths.c \
	src/pathfinding/fc_cover.c \
	src/pathfinding/fc_paths.c \
	src/pathfinding/manage_file.c \
	src/pathfinding/repart_ants.c \
	src/main.c

LSRC	= lib/src/my_putchar.c \
	lib/src/my_putstr.c \
	lib/src/my_printf.c \
	lib/src/my_strlen.c \
	lib/src/my_putnbr.c \
	lib/src/my_getnbr.c \
	lib/src/get_next_line.c \
	lib/src/my_realloc.c \
	lib/src/my_strcpy.c \
	lib/src/my_strdup.c \
	lib/src/my_strcmp.c \
	lib/src/ver_malloc.c \
	lib/src/my_puterror.c \
	lib/src/my_putchar_error.c \
	lib/src/my_strcat.c \
	lib/src/my_strcat_old.c

OBJ	= $(SRC:.c=.o)

LOBJ	= $(LSRC:.c=.o)

CFLAGS	= -I./include -Wall -Wextra -ansi -pedantic -g3


all: $(NAME)

$(NAME): $(OBJ) $(LOBJ)
	ar rc lib/liblemin.a $(LOBJ)
	ranlib lib/liblemin.a
	$(CC) -o $(NAME) $(OBJ) -llemin -lSDL_gfx -Llib/ -lSDL -lSDLmain -lSDL_image

clean: 
	$(RM) $(OBJ)
	$(RM) $(LOBJ)

fclean: clean
	$(RM) lib/liblemin.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
