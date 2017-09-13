//
// InternetSocket.cpp for InternetSocket in /home/lucas_k/TEK2/CPP/cpp_protocole
//
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
//
// Started on  Mon May 16 17:29:30 2016 christophe lucas
// Last update Sun Jun  5 18:26:11 2016 christophe lucas
//

#include "InternetSocket.hh"

InternetSocket::InternetSocket(int port)
{
  InitError();
  Init(port);
  this->protocoleThread = std::thread(&InternetSocket::run, this);
}

InternetSocket::InternetSocket(const std::string &ip, int port)
{
  InitError();
  Init(ip, port);
  this->protocoleThread = std::thread(&InternetSocket::run, this);
}

InternetSocket::~InternetSocket()
{

  this->exit = true;
  this->CloseAll();
  std::lock_guard<std::mutex> guardReceive(this->receiveQueueLock);
  while (!this->receiveQueue.empty())
    {
      delete this->receiveQueue.front();
      this->receiveQueue.pop();
    }
  if (this->protocoleThread.joinable())
    this->protocoleThread.join();
}

int			InternetSocket::Init(int port)
{
  struct protoent	*pe;
  struct sockaddr_in	si_server;
  int			enable = 1;

  /* WINDOWS */
#ifdef WINDOWS
  WSADATA		wsa;

  if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    throw Error("WSAStartup", 0);
#endif

  server = true;
  if (!(pe = getprotobyname("TCP")))
    throw Error("getprotobyname", 0);

  if ((socketFd = socket(AF_INET , SOCK_STREAM, pe->p_proto)) == -1)
    throw Error("socket", errno);

  if (setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR,
		 &enable, sizeof(int)) < 0)
    throw Error("setsockopt(SO_REUSEADDR) failed", errno);
  si_server.sin_family = AF_INET;
  si_server.sin_addr.s_addr = INADDR_ANY;
  si_server.sin_port = htons(port);
  if (bind(socketFd, (struct sockaddr *)&si_server, sizeof(si_server)) < 0)
    throw Error("bind", errno);
  id = -1;
  if (listen(socketFd , 4) == -1)
    throw Error("listen", errno);
  this->exit = false;
  this->socketMax = socketFd;
  std::cerr << "Server Init Succeed" << std::endl;
  return 0;
}

int			InternetSocket::Init(const std::string &ip, int port)
{
  struct sockaddr_in	client;
  struct hostent	*hostinfo;
  Order			*order = NULL;
  int			enable = 1;

  server = false;
  if ((socketFd = socket(AF_INET , SOCK_STREAM, 0)) == -1)
    throw Error("socket", errno);
  if (!(hostinfo = gethostbyname(ip.c_str())))
    throw Error("gethostbyname", 0);

  if (setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR,
		 &enable, sizeof(int)) < 0)
    throw Error("setsockopt(SO_REUSEADDR) failed", errno);
  client.sin_addr = *(struct in_addr *)hostinfo->h_addr;
  client.sin_family = AF_INET;
  client.sin_port = htons(port);
  if (connect(socketFd , (struct sockaddr *)&client , sizeof(struct sockaddr)) < 0)
    throw Error("connect", errno);
  this->receiveSocket(this->socketFd, 0);
  if (!(order = this->Receive()))
    throw Error("receive", 0);
  this->id = (*static_cast<int *>(order->data));
  delete static_cast<char *>(order->data);
  delete order;
  this->exit = false;
  this->socketMax = socketFd;
  std::cerr << "Client " << this->id << " Init Succeed" << std::endl;
  return 0;
}

int				InternetSocket::Accept()
{
  struct sockaddr_in		si_client;
  SOCKET			client_sock;
  int				client_id = 0;
  int				c = sizeof(struct sockaddr_in);
  void				*data;
  std::vector<SOCKET>::iterator	itr;

  if ((client_sock = accept(socketFd, (struct sockaddr *)&si_client, (socklen_t*)&c)) == -1)
    throw Error("accept", errno);
  for (itr = this->clientsFd.begin(); itr != this->clientsFd.end(); itr++)
    {
      if ((*itr) == -1)
	break;
      client_id++;
    }
  if (client_id == this->clientsFd.size())
    clientsFd.resize(this->clientsFd.size() + 1);
  clientsFd[client_id] = client_sock;
  data = operator new(sizeof(int));
  (*static_cast<int *>((data))) = client_id;
  this->Send(NewOrder(client_id, PROTOCOLE::CommandType::CONNECT, sizeof(int), data));
  this->socketMax = (client_sock > this->socketMax) ? client_sock : this->socketMax;
  FD_SET(client_sock, &this->rfds);
  std::cout << "/* new client " << client_id << "*/" << std::endl;
  return client_id;
}

int	InternetSocket::Send(Order *order)
{
  int	fd;
  
  if (!order)
    std::cout << "Order is null" << std::endl;
  if (!order->data)
    std::cout << "OrderData is null" << std::endl;  
  if (server)
    fd = clientsFd[order->header.id];
  else
    fd = socketFd;
  if ((write(fd, &order->header, sizeof(struct OrderHeader))) <= 0)
    throw Error("write", errno);
  if ((write(fd, order->data, order->header.size)) < 0)
    throw Error("write", errno);
  delete static_cast<char *>(order->data);
  delete order;
  return 0;
}

int	InternetSocket::Send(int id, PROTOCOLE::CommandType cmd, void *data, size_t size)
{
  Order	*toSend = new Order();

  toSend->header.id = id;
  toSend->header.size = size;
  toSend->header.command = cmd;
  toSend->data = data;
  return this->Send(toSend);
}


int	InternetSocket::Broadcast(Order *order)
{
  int	it = 0;
  int	size = clientsFd.size();

  for (it = 0; it < size; it++)
    if (this->Send(clientsFd[it], order->header.command, order->data, order->header.size) == -1)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	InternetSocket::Broadcast(PROTOCOLE::CommandType cmd, void *data, size_t size)
{
  int	it = 0;
  int	itsize = clientsFd.size();

  for (it = 0; it < itsize; it++)
    if (this->Send(clientsFd[it], cmd, data, size) == -1)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

Order	*InternetSocket::Receive()
{
  Order	*result = NULL;

  std::lock_guard<std::mutex> guard(this->receiveQueueLock);
  if (!this->receiveQueue.empty())
    {
      result = receiveQueue.front();
      receiveQueue.pop();
    }
  return result;
}

int	InternetSocket::receiveSocket(int fd, int id)
{
  Order	*order;
  int	readSize;

  if (!(order = new Order()))
    throw Error("order", 0);
  if ((readSize = read(fd, &order->header, sizeof(struct OrderHeader))) < 0)
    throw Error("read", errno);
  if (readSize > 0)
    {
      if (!(order->data = operator new(order->header.size + 1)))
	throw Error("new data", 0);
      if (read(fd, order->data, order->header.size) < 0)
	throw Error("read", errno);
      std::lock_guard<std::mutex> guard(this->receiveQueueLock);
      this->receiveQueue.push(order);
    }
  else
    {
      std::cout << "/* exit client " << id << " */" << std::endl;
      close(fd);
      if (server)
	clientsFd[id] = -1;
      order->header.command = PROTOCOLE::CommandType::DISCONNECT;
      order->header.id = id;
      order->header.size = 0;
      order->data = NULL;
      std::lock_guard<std::mutex> guard(this->receiveQueueLock);
      this->receiveQueue.push(order);
      return -1;
    }
  return 0;
}

int	InternetSocket::CloseClient()
{
  int	it = 0;
  int	size = clientsFd.size();

  for (it = 0; it < size; it++)
    if (close(clientsFd[it]) < 0)
      throw Error("close", errno);
  return (EXIT_FAILURE);
}

int	InternetSocket::CloseServer(void)
{
  std::cout << "Closing server" << std::endl;
  if (close(socketFd) < 0)
    throw Error("close", errno);
  socketFd = -1;
#ifdef WINDOWS
  WSACleanup();
#endif
  return (EXIT_SUCCESS);
}

void	InternetSocket::CloseAll(void)
{
  CloseClient();
  CloseServer();
}

int			InternetSocket::run()
{
  int			size;
  int			it;
  struct timeval	tv;

  while (!this->exit)
    {
      tv.tv_sec = 2;
      tv.tv_usec = 0;
      FD_ZERO(&this->rfds);
      FD_SET(this->socketFd, &this->rfds);
      size = clientsFd.size();
      for (it = 0; it < size; it++)
	if (clientsFd[it] != -1)
	  FD_SET(clientsFd[it], &this->rfds);
      if (select(this->socketMax + 1, &this->rfds, NULL, NULL, &tv) == -1)
	throw Error("select", errno);
      if (FD_ISSET(this->socketFd, &this->rfds))
	(this->server) ? this->Accept() : this->receiveSocket(this->socketFd, this->id);
      else
	{
	  size = clientsFd.size();
	  for (it = 0; it < size; it++)
	    if (clientsFd[it] != -1 && FD_ISSET(clientsFd[it], &this->rfds))
	      {
		receiveSocket(clientsFd[it], it);
		break;
	      }
	}
    }
  return 0;
}


Order	*NewOrder(int id, PROTOCOLE::CommandType type, int size, void *data)
{
  Order	*order = new Order();

  order->header.id = id;
  order->header.size = size;
  order->data = data;
  order->header.command = type;
  return order;
}
