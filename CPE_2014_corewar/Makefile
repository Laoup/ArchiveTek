##
## Makefile for asm in /home/guzman_y/prog/epitech/rendu/prog_elem/CPE_2014_corewar
## 
## Made by yoann guzman
## Login   <guzman_y@epitech.net>
## 
## Started on  Sun Apr 12 23:14:12 2015 yoann guzman
## Last update Sun Apr 12 23:14:15 2015 yoann guzman
##

CC	=	cc

RM	=	rm -f

LIB	=	-Llib -lmy$(HOSTTYPE)

CFLAGS	+=	-Wextra -Wall -Werror -g3
CFLAGS	+=	-pedantic
CFLAGS	+=	-I./include

NAME1	=	./asm/asm

NAME2	=	./corewar/corewar

SRCS1	=	./asm/check_funcV2_1.c \
		./asm/check_funcV2.c \
		./asm/check_is_cmd_p.c \
		./asm/convert.c \
		./asm/convert_func.c \
		./asm/create_cor.c \
		./asm/func_2d_tab.c \
		./asm/func_2d_tab2.c \
		./asm/line_cmd_is_true_next.c \
		./asm/put_cmd_in_line_next.c \
		./asm/func_hexa_tab.c \
		./asm/hexa_code.c \
		./asm/parsing.c \
		./asm/search_line.c \
		./asm/treat.c \
		./asm/val_n_ype.c \
		./asm/op.c \
		./asm/main.c

SRCS2	=	./corewar/main.c \
		./corewar/check1.c \
		./corewar/convert.c \
		./corewar/fill_struct.c \
		./corewar/op.c


OBJS1	=	$(SRCS1:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

all	:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
		make -C lib
		$(CC) -o $(NAME1) $(OBJS1) $(LIB)

$(NAME2):	$(OBJS2)
		$(CC) -o $(NAME2) $(OBJS2) $(LIB)

clean	:
		$(RM) $(OBJS1)
		$(RM) $(OBJS2)
		make clean -C lib

fclean	:	clean
		$(RM) $(NAME1)
		$(RM) $(NAME2)
		make fclean -C lib

re	:	fclean all

.PHONY	:	all clean fclean re
