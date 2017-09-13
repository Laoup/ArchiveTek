CC	:= g++

RM	:= cmd \/C del /S

CFLAGS	+= -I./include -I./include/network -I./include/keylogger -IC:\libs\boost_1_62_0 -IC:\Program\ Files\ \(x86\)\GnuWin32\include -std=c++11 -Wno-deprecated-declarations

LDFLAGS := -L./lib -lboost_system-mgw53-mt-1_62 -lboost_serialization-mgw53-mt-1_62 -lboost_thread-mgw53-mt-1_62 -lws2_32

SRCPATH := ./src

SRCS	:= $(SRCPATH)/network/NetworkProtocol.cpp \
		$(SRCPATH)/keylogger/Keylog.cpp \
		$(SRCPATH)/keylogger/Keylogger.cpp \
		$(SRCPATH)/Client.cpp \
		$(SRCPATH)/main.cpp

OBJS	:= $(SRCS:.cpp=.o)

NAME	:= spider_client

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME).exe

re: fclean all

.PHONY: all re clean fclean
