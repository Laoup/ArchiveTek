##
## Makefile
## 
## Made by AceyT
## Login   <aceyt@epitech.net>
## 
## Started on  Thu Feb 11 11:25:26 2016 AceyT
## Last update Tue Jul  5 17:38:46 2016 Alban Meurice
##

RM		= rm -f

CXX		= g++

NAME		= nanotekspice

SRCDIR		= src
INCDIR		= include

CXXFLAGS	+= -Wall -Wextra -Werror
CXXFLAGS	+= -I./ -I./$(INCDIR)/
CXXFLAGS	+= -std=c++11

SRCS		= $(SRCDIR)/main.cpp \
		  $(SRCDIR)/addrLine.cpp \
		  $(SRCDIR)/format.cpp \
		  $(SRCDIR)/regex.cpp \
		  $(SRCDIR)/search2.cpp \
		  $(SRCDIR)/search.cpp \
##		  $(SRCDIR)/

OBJS		= $(SRCS:.cpp=.o)

##<VISUAL CMD>

ECHO		=	echo -e

YELLOW		=	"\033[0;33m"
GREEN		=	"\033[0;32m"
RED		=	"\033[0;31m"
RESET		=	"\033[0;0m"

##</VISUAL CMD>

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)
	@$(ECHO) $(GREEN)">Project \""$(NAME)"\" compiled" $(RESET)

clean:
	$(RM) $(OBJS)
	@$(ECHO) $(YELLOW) "Directories  clean" $(RESET)

fclean: clean
	$(RM) $(NAME)
	@$(ECHO) $(RED) "Directories full clean" $(RESET)

re: fclean all

test: all
	./$(NAME) ressource

.PHONY: all clean fclean re test
