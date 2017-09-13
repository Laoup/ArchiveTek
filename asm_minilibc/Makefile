##
## Makefile for libasm in /home/thomas/projet/asm_minilibc/
##
## Made by Jamais Thomas
## Login   <jamais_t@epitech.eu>
##
## Started on  Thu Mar 17 12:28:42 2016 Jamais Thomas
## Last update Sun Mar 27 22:28:50 2016 Alban Meurice
##

ASM		=	nasm

SRC 		=	strlen.S \
			strchr.S \
         memset.S \
			memcpy.S \
			memmove.S \
			strcmp.S \
         strstr.S \
			strncmp.S \
			rindex.S \
         strpbrk.S \
         strcasecmp.S \
			strcspn.S

OBJ		=	$(SRC:.S=.o)

ASMFLAGS	=	-f elf64

NAME		=	libasm.so

%.o:			%.S
			${ASM} $< ${ASMFLAGS} -o $@

${NAME}:		$(OBJ)
			gcc -shared -o $(NAME) $(OBJ)

all:			${NAME}

clean:
			rm -f $(OBJ)

fclean:			clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:   all clean fclean re
