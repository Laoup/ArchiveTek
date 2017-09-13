/*
** NetworkProtocol.hh for cpp_spider in /home/tarkick/repos/cpp_spider/include/network
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Tue Nov 08 12:47:58 2016 tarkick
** Last update Wed Nov 09 01:55:46 2016 tarkick
*/

#ifndef NETWORKPROTOCOL_HH_
# define NETWORKPROTOCOL_HH_

# include <cstdint>
# include <iostream>
# include <istream>
# include <ostream>
# include <boost/asio.hpp>
# include <boost/bind.hpp>
# include <boost/archive/text_oarchive.hpp>
# include <boost/archive/text_iarchive.hpp>
# include <boost/enable_shared_from_this.hpp>
# include <boost/shared_ptr.hpp>
# include "NetworkPacket.hh"

using namespace					boost;
using namespace					boost::asio;

namespace						Net
{

	class								Protocol : public enable_shared_from_this<Protocol>
	{

		public:

			static shared_ptr<Protocol> create(io_service &ios, Type type) // (1)
			{
				return shared_ptr<Protocol>(new Protocol(ios, type));
			}

			//OPERATIONS HANDLERS
			void 						handleReceivingHeader(const boost::system::error_code &err, size_t bytes);
			void 						handleReceivingData(const boost::system::error_code &err, size_t bytes);
			void 						handleSending(const boost::system::error_code &err, size_t bytes);

			//OPERATIONS
			void 						send(Net::Opcode::Server opcode);
			void 						send(Net::Opcode::Client opcode, char key);
			void 						send(Net::Opcode::Client opcode);
			void 						receive();

			void 						timeout()
			{
				std::cerr << "Connection timed out" << std::endl;
				socket_.close();
			};

			//GETTERS
			ip::tcp::socket				&getSocket()
			{
				return 					socket_;
			};

		private:
			Protocol(io_service &ios, Type type);

			ClientServerData			clientPacket_;
			ServerClientData			serverPacket_;
			ip::tcp::socket				socket_;

			//PACKET
			Type						type_;
			std::vector<char>			headerIn_;
			std::vector<char>			dataIn_;
			std::string					headerOut_;
			std::string					dataOut_;

	};

};

#endif
