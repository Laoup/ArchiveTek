/*
** Server.cpp for cpp_spider in /home/tarkick/repos/cpp_spider/src/server
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:28:17 2016 tarkick
// Last update Thu Nov 10 18:15:13 2016 Pierrick Garcia
*/

#include "Server.hh"

Server::Server(unsigned int port) : Network<SERVER>(port, SERVER)
{
  accept();
  run();
}

Server::~Server()
{
}

void			Server::processingClient(boost::shared_ptr<Protocol> client)
{
  send(client, Net::Opcode::Server::CONFIRM);
  receive(client);
}
