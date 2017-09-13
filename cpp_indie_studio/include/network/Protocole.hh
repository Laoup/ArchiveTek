//
// protocole.hh for protocole in /home/lucas_k/TEK2/CPP/protocole
//
// Made by christophe lucas
// Login   <lucas_k@epitech.net>
//
// Started on  Mon May 16 17:19:38 2016 christophe lucas
// Last update Sun Jun  5 17:40:07 2016 christophe lucas
//

#ifndef PROTOCOLE_HH_
# define PROTOCOLE_HH_

# include <string>
# include <vector>
# include "ErrorControler.hh"

# ifndef WINDOWS
typedef	int	SOCKET;
# endif

namespace PROTOCOLE
{
  enum class				CommandType
  {
    // server commands
    SHUTDOWN = 100,
      ADD_ROOM = 101,
      RM_ROOM = 102,
      JOIN_ROOM = 103,
      QUIT_ROOM = 104,
      LIST_ROOM = 105,
      DISCONNECT = 106,
      START_GAME = 107,
      PAS2PLACE = 108,
    // client commands
      EXIT = 5,
      MOVE = 6,
      PRINT = 7,
      SET = 8,
      GET = 9,
      CONNECT = 10,
      CLIENT_STATUS = 11,
      NEW_MESH = 12,
      DELETE_MESH = 13,
      UPDATE_PV = 14
      };
};

struct					OrderHeader
{
  int					id;
  PROTOCOLE::CommandType		command;
  size_t				size;
};

struct					Order
{
  OrderHeader				header;
  void					*data;
};

class					IProtocole
{
protected:
  virtual int				Accept() = 0;
  virtual int				CloseClient() = 0;
  virtual int				CloseServer(void) = 0;
  virtual int				receiveSocket(int, int) = 0;
  virtual int				Init(int) = 0;
  virtual int				Init(const std::string &, int) = 0;

public:
  virtual				~IProtocole() {};
  virtual int				Send(Order *) = 0;
  virtual int				Send(int, PROTOCOLE::CommandType, void *, size_t) = 0;
  virtual int				Broadcast(Order *) = 0;
  virtual int				Broadcast(PROTOCOLE::CommandType, void *, size_t) = 0;
  virtual Order				*Receive() = 0;
  virtual void				CloseAll(void) = 0;
  virtual std::vector<SOCKET>		*getClientSockets() = 0;
  virtual SOCKET			getSocket() = 0;
  virtual int				getId() = 0;
};

Order					*NewOrder(int, PROTOCOLE::CommandType, int, void *);

#endif /* !PROTOCOLE_HH_ */
