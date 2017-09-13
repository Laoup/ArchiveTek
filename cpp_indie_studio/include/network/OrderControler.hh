//
// OrderControler.hh for indie-studio in /home/grosso_a/Workspace/indie-studio/include/
//
// Made by Arthur Grosso
// Login   <grosso_a@epitech.eu>
//
// Started on  Tue May 24 00:15:15 2016 Arthur Grosso
// Last update Sun Jun  5 17:35:36 2016 christophe lucas
//
#ifndef ORDERCONTROLER_HH_
# define ORDERCONTROLER_HH_

# include <string>
# include <list>
# include <stdlib.h>
# include <thread>
# include <unistd.h>
# include <time.h>
# include "network/Protocole.hh"

typedef int (*OrderFunction)(void *, Order *);

struct OrderCommand
{
  PROTOCOLE::CommandType		command;
  OrderFunction				ptr;
  void					*staticdata;
};

class					OrderControler
{
public:
  OrderControler(int port) {Init(port);};
  OrderControler(const std::string &addr, int port) {Init(addr, port);};
  ~OrderControler();
  void					setDefaultOrder(OrderFunction, void *);
  IProtocole				*getProtocole() {return protocole;};
  bool					addOrder(PROTOCOLE::CommandType, OrderFunction, void *);
  int					sendOrder(Order *);
  int					sendOrder(int, PROTOCOLE::CommandType, size_t, void *);
  int					run();

private:
  std::list<OrderCommand *>		commands;
  bool					server;
  IProtocole				*protocole;
  std::thread 				task;
  bool					exit;
  OrderFunction				dispatchOrder;
  void					*dispatchOrderData;
  bool					setPtr(PROTOCOLE::CommandType, OrderFunction);
  OrderFunction				getPtr(PROTOCOLE::CommandType);
  bool					isOrder(PROTOCOLE::CommandType);
  OrderCommand				*getOrder(PROTOCOLE::CommandType);
  int					execOrder(Order *);
  int					OrderLoop();
  int					Init(int);
  int					Init(const std::string &, int);
};

#endif /* !ORDERCONTROLER_HH_ */
