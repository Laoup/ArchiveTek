//
// InternetSocket.hh for INTERNETSOCKET_HH_ in /home/lucas_k/TEK2/CPP/cpp_indie_studio.VERRYIMPORTANT/indie-studio
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sun Jun  5 17:32:17 2016 christophe lucas
// Last update Sun Jun  5 17:34:57 2016 christophe lucas
//

#ifndef INTERNETSOCKET__HH__
# define INTERNETSOCKET__HH__

# include <vector>
# include <queue>
# include <thread>
# include <mutex>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <iostream>
# include <thread>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>

# ifdef WINDOWS
#  include <winsock2.h>
#  pragma comment(lib,"ws2_32.lib")
# else
#  include <sys/socket.h>
#  include <netdb.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
# endif

# include "Protocole.hh"

class InternetSocket :			public IProtocole
{
public:
					InternetSocket(int);
					InternetSocket(const std::string &, int);
					~InternetSocket();
  int					Send(Order *);
  int					Send(int, PROTOCOLE::CommandType, void *, size_t);
  int					Broadcast(Order *);
  int					Broadcast(PROTOCOLE::CommandType, void *, size_t);
  Order					*Receive();
  void					CloseAll(void);
  std::vector<SOCKET>			*getClientSockets() {return &this->clientsFd;};
  SOCKET				getSocket() {return this->socketFd;};
  int					getId() {return this->id;};

private:
  std::queue<Order *>			receiveQueue;
  std::mutex				receiveQueueLock;
  std::vector<SOCKET>			clientsFd;
  SOCKET				socketFd;
  int					socketMax;
  int					id;
  fd_set				rfds;
  bool					exit;
  bool					server;
  std::thread				protocoleThread;

  int					Accept();
  int					CloseClient();
  int					CloseServer(void);
  int					receiveSocket(int, int);
  void					InitError();
  int					Init(int);
  int					Init(const std::string &, int);
  int					run();
};

#endif /* !INTERNETSOCKET__HH__ */
