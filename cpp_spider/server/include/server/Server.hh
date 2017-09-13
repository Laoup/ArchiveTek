/*
** Server.hh for cpp_spider in /home/tarkick/repos/cpp_spider/include/server
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:27:02 2016 tarkick
** Last update Tue Nov 08 20:00:32 2016 tarkick
*/

#ifndef SERVER_HH_
# define SERVER_HH_

# include "Network.hh"

using namespace		Net;

class				Server : public Network<SERVER>
{

public:
	Server(unsigned int port);
	~Server();

	virtual void 	processingClient(boost::shared_ptr<Protocol> client);

private:

};

#endif
