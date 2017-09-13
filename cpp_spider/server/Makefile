CC	:= g++

RM	:= rm -rf

CFLAGS	+= -I./include -I./include/network -I./include/client -I./include/server -I./include/database -Wall -Wextra -W -std=c++11 -Wno-deprecated-declarations

LDFLAGS := -lboost_system -lboost_date_time -lboost_thread -lboost_serialization -lpthread -lX11

CSRCPATH := ./src/client

SSRCPATH := ./src/server

CSRCS	:= src/network/NetworkProtocol.cpp \
		$(CSRCPATH)/Keylogger.cpp \
		$(CSRCPATH)/main.cpp \
		$(CSRCPATH)/Client.cpp

SSRCS	:= src/network/NetworkProtocol.cpp \
		$(SSRCPATH)/main.cpp \
		$(SSRCPATH)/Server.cpp \
		src/database/Database.cpp

COBJS	:= $(CSRCS:.cpp=.o)

SOBJS	:= $(SSRCS:.cpp=.o)

CNAME	:= spider_client

SNAME	:= spider_server


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(CNAME) $(SNAME)

client: $(CNAME)

server: $(SNAME)

$(CNAME): $(COBJS)
	$(CC) -o $(CNAME) $(COBJS) $(CFLAGS) $(LDFLAGS)

$(SNAME): $(SOBJS)
	$(CC) -o $(SNAME) $(SOBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(COBJS) $(SOBJS)

fclean: clean
	$(RM) $(CNAME) $(SNAME)

re: fclean all

.PHONY: all re clean fclean
