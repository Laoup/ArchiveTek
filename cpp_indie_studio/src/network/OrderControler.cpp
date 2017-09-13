//
// OrderControler.cpp for OrderController in /home/lucas_k/TEK2/CPP/cpp_indie_studio.VERRYIMPORTANT/indie-studio/src/network
// 
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
// 
// Started on  Sun Jun  5 18:26:49 2016 christophe lucas
// Last update Sun Jun  5 18:27:36 2016 christophe lucas
//

#include "network/OrderControler.hh"
#include "network/InternetSocket.hh"

OrderControler::~OrderControler()
{
  this->exit = true;
  if (!this->commands.empty())
    while (!this->commands.empty())
      {
	free(this->commands.front());
	this->commands.pop_front();
      }
  if (this->task.joinable())
    this->task.join();
  delete this->protocole;
}

int OrderControler::Init(int port)
{
  this->server = true;
  this->exit = false;
  this->protocole = new InternetSocket(port);
  this->dispatchOrder = NULL;
  return 0;
}

int OrderControler::Init(const std::string &ip, int port)
{
  this->server = false;
  this->exit = false;
  this->protocole = new InternetSocket(ip, port);
  this->dispatchOrder = NULL;
  return 0;
}

void OrderControler::setDefaultOrder(OrderFunction orderfct, void *data)
{
  this->dispatchOrder = orderfct;
  this->dispatchOrderData = data;
}

bool OrderControler::addOrder(PROTOCOLE::CommandType type, OrderFunction ptr, void *data)
{
  OrderCommand *newElement;

  if (!getOrder(type))
    {
      if (!(newElement = (OrderCommand *)malloc(sizeof(Order))))
	     return false;
      newElement->command = type;
      newElement->ptr = ptr;
      newElement->staticdata = data;
      this->commands.push_front(newElement);
      return true;
    }
  return false;
}

bool OrderControler::setPtr(PROTOCOLE::CommandType type, OrderFunction ptr)
{
  OrderCommand *el;

  if (!(el = getOrder(type)))
    return false;
  el->ptr = ptr;
  return true;
}

OrderFunction	OrderControler::getPtr(PROTOCOLE::CommandType type)
{
  OrderCommand *el;

  if (!(el = getOrder(type)))
    return NULL;
  return el->ptr;
}

bool OrderControler::isOrder(PROTOCOLE::CommandType type)
{
  if (!getOrder(type))
    return false;
  return true;
}

int OrderControler::execOrder(Order *order)
{
  OrderCommand	*el = NULL;

	if ((el = getOrder(order->header.command)))
		(el->ptr)(el->staticdata, order);
	else if (server && dispatchOrder)
		(dispatchOrder)(dispatchOrderData, order);
	delete static_cast<char *>(order->data);
	delete order;
	return 0;
}

OrderCommand				*OrderControler::getOrder(PROTOCOLE::CommandType type)
{
  std::list<OrderCommand *>::iterator	itr;

  for (itr = this->commands.begin(); itr != this->commands.end(); itr++)
    if ((*itr)->command == type)
      break;
  if (itr == this->commands.end())
    return NULL;
  return *itr;
}

int	OrderControler::sendOrder(Order *order)
{
  return protocole->Send(order);
}

int	OrderControler::sendOrder(int id, PROTOCOLE::CommandType type, size_t dataSize, void *data)
{
  return protocole->Send(id, type, data, dataSize);
}

int	OrderControler::OrderLoop()
{
  Order	*order = NULL;

  while (!this->exit)
    {
      while (!this->exit && !(order = protocole->Receive()))
	usleep(1000);
      if (this->exit)
	break;
      else if (order->header.command == PROTOCOLE::CommandType::EXIT)
	this->exit = true;
      else
	execOrder(order);
    }
  return 0;
}

int OrderControler::run()
{
  this->task = std::thread(&OrderControler::OrderLoop, this);
  return 0;
}
