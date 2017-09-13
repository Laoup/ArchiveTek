/*
** main.cpp for cpp_spider in /home/tarkick/repos/cpp_spider/src/client
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:26:15 2016 tarkick
** Last update Wed Nov 09 03:01:41 2016 tarkick
*/

#include <exception>
#include <cstdlib>
#include "Client.hh"

int 			main(int ac, char **av)
{
	try
	{
		if (ac >= 3)
			Client 	client(std::string(av[1]), atoi(av[2]));
		else
			std::cerr << "Usage: ./spider_client [ip] [port]" << std::endl;
	}
	catch (std::exception &error)
	{
		std::cerr << "Spider_client: " << error.what() << std::endl;
	}
	return 	0;
}
