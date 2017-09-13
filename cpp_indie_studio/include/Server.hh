//
// Server.hh for server_Object in /home/meuric_a/Projet_T2/Indie/indie-studio/include
//
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
//
// Started on  Fri May 20 18:31:38 2016 Alban Meurice
// Last update Sun Jun  5 17:11:05 2016 christophe lucas
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include "OrderControler.hh"
# include "OrderData.hh"
# include <list>
# include <string>
# include <iostream>

struct				PlayerData
{
  int				id;
  int				status;
};

struct				Room
{
  std::string			roomName;
  int				nbPlayerMax;
  std::list<PlayerData *>	players;
  bool				lock;
};

class				Server
{
public:
  Server();
  Server(int);
  ~Server();
  int				Init(int);
  void				Run();

  static int			addRoom(void *, Order *);
  static int			closeRoom(void *, Order *);
  static int			addPlayerToRoom(void *, Order *);
  static int			rmPlayerToRoom(void *, Order *);
  static int			statusPlayer(void *, Order *);
  static int			listRoom(void *, Order *);
  static int			disconnectClient(void *, Order *);

  OrderControler		*control;

private:
  std::list<Room*>		rooms;
  bool				exit;
  // manage rooms
  std::list<Room*>::iterator	findPlayer(int);
  std::list<Room*>::iterator	findRoom(const std::string &);
  static int			defaultOrder(void *, Order *);
  static int			shutdownServer(void *, Order *);
};

#endif /* SERVER_HH_ */
