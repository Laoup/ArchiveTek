//
// server_a.cpp for server_a in /home/meuric_a/Projet_T2/Indie/indie-studio/src
//
// Made by Alban Meurice
// Login   <meuric_a@epitech.net>
//
// Started on  Fri May 20 18:25:39 2016 Alban Meurice
// Last update Sun Jun  5 18:19:16 2016 christophe lucas
//

#include "Player.hh"
#include "Server.hh"
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>

Server::Server(int port)
  : control(NULL), exit (false)
{
  Init(port);
}

Server::Server()
  : control(NULL), exit (false)
{
}

int Server::Init(int port)
{
  this->control = new OrderControler(port);
  this->control->setDefaultOrder((OrderFunction)
				 &Server::defaultOrder,
				 (void *)this);
  this->control->addOrder(PROTOCOLE::CommandType::ADD_ROOM,
			  (OrderFunction)&Server::addRoom,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::RM_ROOM,
			  (OrderFunction)&Server::closeRoom,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::JOIN_ROOM,
			  (OrderFunction)&Server::addPlayerToRoom,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::QUIT_ROOM,
			  (OrderFunction)&Server::rmPlayerToRoom,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::LIST_ROOM,
			  (OrderFunction)&Server::listRoom,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::SHUTDOWN,
			  (OrderFunction)&Server::shutdownServer,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::DISCONNECT,
			  (OrderFunction)&Server::disconnectClient,
			  static_cast<void *>(this));
  this->control->addOrder(PROTOCOLE::CommandType::CLIENT_STATUS,
			  (OrderFunction)&Server::statusPlayer,
			  static_cast<void *>(this));
  this->control->run();
  return EXIT_SUCCESS;
}

Server::~Server()
{
  while (!rooms.empty())
    {
      rooms.front()->players.clear();
      while (rooms.front()->players.empty())
	{
	  delete rooms.front()->players.front();
	  rooms.front()->players.pop_front();
	}
      delete rooms.front();
      rooms.pop_front();
    }
  if (this->control != NULL)
    delete this->control;
}

void Server::Run()
{
  while (!this->exit)
    sleep(1);
  std::cout << "/* shutdown Server */" << std::endl;
}

std::list<Room *>::iterator	Server::findPlayer(int id)
{
  std::list<Room *>::iterator	itrRoom;
  std::list<PlayerData *>::iterator	itrPlayer;

  for (itrRoom = rooms.begin(); itrRoom != rooms.end(); itrRoom++)
    for (itrPlayer = (*itrRoom)->players.begin();
	 itrPlayer != (*itrRoom)->players.end(); itrPlayer++)
      if ((*itrPlayer)->id == id)
	return itrRoom;
  return itrRoom;
}

std::list<Room *>::iterator	Server::findRoom(const
						 std::string
						 &name)
{
  std::list<Room *>::iterator	itrRoom;

  for (itrRoom = rooms.begin(); itrRoom != rooms.end(); itrRoom++)
    if ((*itrRoom)->roomName == name)
      return itrRoom;
  return itrRoom;
}

int		Server::statusPlayer(void *staticdata, Order *orderdata)
{
  ClientStatus	*data = static_cast<ClientStatus *>(orderdata->data);
  Server	*server = static_cast<Server *>(staticdata);
  std::list<Room *>::iterator		itrRoom;
  std::list<PlayerData *>::iterator	itrPlayer;

  if ((itrRoom = server->findRoom
       (((NewRoom *)orderdata->data)->name)) != server->rooms.end())
    {
      (*itrRoom)->lock = true;
      for (itrPlayer = (*itrRoom)->players.begin();
	   itrPlayer != (*itrRoom)->players.end(); itrPlayer++)
        if ((*itrPlayer)->id == orderdata->header.id)
          (*itrPlayer)->status = data->status;
      std::cout << "/* player " << orderdata->header.id
		<< "change status " << data->status << "*/" << std::endl;
      for (itrPlayer = (*itrRoom)->players.begin();
	   itrPlayer != (*itrRoom)->players.end(); itrPlayer++)
        if ((*itrPlayer)->status != 2)
	  break;
      if (itrPlayer == (*itrRoom)->players.end())
	{
	  for (itrPlayer = (*itrRoom)->players.begin();
	       itrPlayer != (*itrRoom)->players.end();
	       itrPlayer++)
	    server->control->sendOrder((*itrPlayer)->id,
				       PROTOCOLE::CommandType::START_GAME, 0, NULL);
	  std::cout << "/* Run game */" << std::endl;
	}
    }
  else
    std::cout << "/* The room not exist */" << std::endl;
  return 0;
}


int		Server::addRoom(void *staticdata, Order *orderdata)
{
  Server	*server = static_cast<Server *>(staticdata);
  Room		*room;

  if (server->findRoom((static_cast<NewRoom *>(orderdata->data))
		       ->name) == server->rooms.end())
    {
      room = new Room;
      room->roomName = (static_cast<NewRoom *>(orderdata->data))
	->name;
      room->nbPlayerMax = (static_cast<NewRoom *>
			   (orderdata->data))->size;
      room->lock = false;
      room->players.clear();
      server->rooms.push_front(room);
      std::cout << "/* addRoom " << room->roomName
		<< " */"<< std::endl;
    }
  return 0;
}

int	Server::closeRoom(void *staticdata, Order *orderdata)
{
  std::list<Room *>::iterator	itrRoom;
  Server			*server =
    static_cast<Server *>(staticdata);
  std::string			name =
    (char *)orderdata->data;

  if ((itrRoom = server->findRoom(name)) != server->rooms.end())
    {
      while (!(*itrRoom)->players.empty())
	{
	  delete (*itrRoom)->players.front();
	  (*itrRoom)->players.pop_front();
	}
      itrRoom = server->rooms.erase(itrRoom);
      std::cout << "/* rmRoom " << name << " */"<< std::endl;
    }
  return 0;
}

int	Server::addPlayerToRoom(void *staticdata, Order *orderdata)
{
  Server				*server =
    static_cast<Server *>(staticdata);
  std::list<Room *>::iterator		itrRoom;
  std::string				name;
  std::list<PlayerData *>::iterator		itrPlayer;
  PlayerData				*newplayer;

  name = (char *)(&((NewRoom *)orderdata->data)->name);
  if ((itrRoom = server->findRoom(name)) != server->rooms.end())
    {
      if ((*itrRoom)->players.size() == 0)
        (*itrRoom)->lock = 0;
      if ((*itrRoom)->lock)
	{
	  std::cout << "/* the room is lock */" << std::endl;
	  server->control->sendOrder(orderdata->header.id,
				     PROTOCOLE::CommandType::PAS2PLACE, 0, NULL);
	}
      else if ((*itrRoom)->players.size() >= (*itrRoom)->nbPlayerMax)
        {
	  std::cout << "/* the room is full */" << std::endl;
	  server->control->sendOrder(orderdata->header.id,
				     PROTOCOLE::CommandType::PAS2PLACE, 0, NULL);
	}
      else
	{
	  for (itrPlayer = (*itrRoom)->players.begin();
	       itrPlayer != (*itrRoom)->players.end();
	       itrPlayer++)
	    if ((*itrPlayer)->id == orderdata->header.id)
	      break;
	  if (itrPlayer == (*itrRoom)->players.end())
	    {
	      newplayer = new PlayerData();
	      newplayer->id = orderdata->header.id;
	      newplayer->status = 0;
	      (*itrRoom)->players.push_front(newplayer);
	      std::cout << "/* player " << orderdata->header.id
			<< " join the room " << name << "*/"
			<< std::endl;
	    }
	  else
	    std::cout << "/* player is already in the room */"
		      << std::endl;
	}
    }
  else
    std::cout << "/* The room not exist */" << std::endl;
  return 0;
}

int	Server::rmPlayerToRoom(void *staticdata, Order *orderdata)
{
  Server			*server =
    static_cast<Server *>(staticdata);
  std::list<Room *>::iterator	itrRoom;
  std::string			name =
    (char *)(&((NewRoom *)orderdata->data)->name);
  std::list<PlayerData *>::iterator	itrPlayer;

  if ((itrRoom = server->findRoom(name)) != server->rooms.end())
    {
      for (itrPlayer = (*itrRoom)->players.begin();
	   itrPlayer != (*itrRoom)->players.end(); itrPlayer++)
	if ((*itrPlayer)->id == orderdata->header.id)
	  {
	    delete (*itrPlayer);
	    itrPlayer = (*itrRoom)->players.erase(itrPlayer);
	    std::cout << "/* player " << orderdata->header.id 
		      << " quit the room " << name << "*/" << std::endl;
	    return 0;
	  }
      std::cout << "/* player is not in the room */" << std::endl;
    }
  else
    std::cout << "/* The room not exist */" << std::endl;
  return 0;
}

int	Server::disconnectClient(void *staticdata,
				 Order *orderdata)
{
  std::list<Room *>::iterator	itrRoom;
  Server			*server =
    static_cast<Server *>(staticdata);
  std::list<PlayerData *>::iterator	itrPlayer;

  if (orderdata->header.id != -1)
    {
      for (itrRoom = server->rooms.begin(); itrRoom
	     != server->rooms.end(); itrRoom++)
	for (itrPlayer = (*itrRoom)->players.begin();
	     itrPlayer != (*itrRoom)->players.end(); itrPlayer++)
	  if ((*itrPlayer)->id == orderdata->header.id)
	    {
	      delete (*itrPlayer);
	      itrPlayer = (*itrRoom)->players.erase(itrPlayer);
	      std::cout << "/* player " << orderdata->header.id
			<< " quit the room " <<
		(*itrRoom)->roomName << "*/" << std::endl;
	      return 0;
	    }
    }
  return 0;
}

int	Server::listRoom(void *staticdata, Order *orderdata)
{
  std::list<Room *>::iterator	itrRoom;
  Server			*server =
    static_cast<Server *>(staticdata);
  std::string			rooms;
  char				*listRoom;

  itrRoom = server->rooms.begin();
  while (itrRoom != server->rooms.end())
    {
      rooms += (*itrRoom)->roomName;
      itrRoom++;
      if (itrRoom != server->rooms.end())
	rooms += std::string("/");
    }
  listRoom = static_cast<char *>((operator new(sizeof(char) * rooms.size() + 1)));
  strncpy(listRoom, rooms.c_str(), rooms.size());
  server->control->sendOrder(orderdata->header.id, orderdata->header.command,
			     sizeof(char) * rooms.size() + 1, listRoom);
  return 0;
}

int					Server::defaultOrder(void *staticdata, Order *orderdata)
{
  std::list<Room *>::iterator		itrRoom;
  std::list<PlayerData *>::iterator	itrPlayer;
  Server				*server = static_cast<Server *>(staticdata);
  void					*data;

  if ((itrRoom = (static_cast<Server *>(staticdata))
       ->findPlayer(orderdata->header.id)) != server->rooms.end())
    {
      for (itrPlayer = (*itrRoom)->players.begin();
	   itrPlayer != (*itrRoom)->players.end(); itrPlayer++)
	if ((*itrPlayer)->id != orderdata->header.id)
	  {
	    data = operator new(orderdata->header.size);
	    memcpy(data, orderdata->data, orderdata->header.size);
	    server->control->sendOrder((*itrPlayer)->id, orderdata->header.command,
				       orderdata->header.size, data);
	  }
    }
  else
    std::cout << "Id not found" << std::endl;
  return 0;
}

int	Server::shutdownServer(void *staticdata, Order *orderdata)
{
  static_cast<void>(orderdata);
  (static_cast<Server *>(staticdata))->exit = true;
  return 0;
}

ErrorControler error = ErrorControler();

int		main(int argc, char **argv)
{
  Server	server;
  NewRoom	*room;
  int		port;

  if (argc < 2)
    {
      std::cerr << "usage: "<< argv[0] << " port" << std::endl;
      return EXIT_FAILURE;
    }
  try
    {
      port = std::stoi(argv[1]);
      if (port < 0)
	{
	  std::cerr << "usage: "<< argv[0] << " port"
		    << std::endl;
	  std::cerr << "invalid port" << std::endl;
	  return EXIT_FAILURE;
	}
      server.Init(port);
      room = new NewRoom();
      strcpy(room->name,
	     (char *)std::string("Principale").c_str());
      room->size = NB_PLAYER;
      Server::addRoom((void *)&server,
		      NewOrder(-1, PROTOCOLE::CommandType::
			       LIST_ROOM,
			       sizeof(struct NewRoom), room));
      server.Run();
    }
  catch (std::exception const& e)
    {
      std::cerr << "ERREUR : " << e.what() << std::endl;
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
