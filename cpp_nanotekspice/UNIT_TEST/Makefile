##
## Makefile
## 
## Made by AceyT
## Login   <aceyt@epitech.net>
## 
## Started on  Fri Feb 19 13:02:20 2016 AceyT
## Last update Sat Feb 27 00:15:59 2016 AceyT
##

RM		= rm -f

CXX		= g++

SRCDIR		= ../src
INCDIR		= ../inc

CXXFLAGS	+= -W -Wall -Werror -std=c++11 -g3
CXXFLAGS	+= -I ../ -I./$(INCDIR)/

## ------ FEEDER
TEST_FEEDER	= test_feeder

SRCS_FEEDER	= main_feeder_test.cpp \
		  $(SRCDIR)/pars/Feeder.cpp

OBJS_FEEDER	= $(SRCS_FEEDER:.cpp=.o)
##------ /FEEDER
##------ ERROR
TEST_ERROR	= test_error

SRCS_ERROR	= main_error_test.cpp \
		  $(SRCDIR)/pars/Error.cpp

OBJS_ERROR	= $(SRCS_ERROR:.cpp=.o)
##------ /ERROR
##------ TREE
TEST_TREE	= test_tree 

SRCS_TREE	= main_treecreator_test.cpp \
		  $(SRCDIR)/pars/TreeCreator.cpp \
		  $(SRCDIR)/pars/Error.cpp \
		  $(SRCDIR)/pars/Parser.cpp \
		  $(SRCDIR)/pars/Feeder.cpp

OBJS_TREE	= $(SRCS_TREE:.cpp=.o)
##------ /TREE

#TEST_		= 

#SRCS_		= main_.cpp \
#		  $(SRCDIR)/

#OBJS_		= $(SRCS_:.cpp=.o)



all: $(TEST_FEEDER) $(TEST_ERROR) $(TEST_TREE)

$(TEST_FEEDER): $(OBJS_FEEDER)
	$(CXX) -o $(TEST_FEEDER) $(OBJS_FEEDER)

$(TEST_ERROR): $(OBJS_ERROR)
	$(CXX) -o $(TEST_ERROR) $(OBJS_ERROR)

$(TEST_TREE): $(OBJS_TREE)
	$(CXX) -o $(TEST_TREE) $(OBJS_TREE)


#$(TEST_): $(OBJS_)
#	$(CXX) -o $(TEST_) $(OBJS_)

clean:
	$(RM) $(OBJS_FEEDER)
	$(RM) $(OBJS_ERROR)
	$(RM) $(OBJS_TREE)
#	$(RM) $(OBJS_)


fclean: clean
	$(RM) $(TEST_FEEDER)
	$(RM) $(TEST_ERROR)
	$(RM) $(TEST_TREE)
#	$(RM) $(TEST_)

re: fclean all

test: all
	./$(TEST_FEEDER)
	@echo "---TEST_FEEDER DONE---"
	./$(TEST_ERROR)
	@echo "---TEST_ERROR DONE-"
	./$(TEST_TREE)
	@echo "---TEST_ DONE---"
#	./$(TEST_)
#	@echo "---TEST_ DONE---"

.PHONY: all clean fclean re test
