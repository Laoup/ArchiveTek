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
# include <openssl/rsa.h>
# include <openssl/pem.h>
# include <boost/asio.hpp>
# include <boost/bind.hpp>
# include <boost/archive/text_oarchive.hpp>
# include <boost/archive/text_iarchive.hpp>
# include <boost/enable_shared_from_this.hpp>
# include <boost/shared_ptr.hpp>
# include "NetworkPacket.hh"
# include "Keylog.hh"

using namespace							boost;
using namespace							boost::asio;


namespace								Net
{

	template 							<Type>
	class								Network;

	template 							<>
	class								Network<CLIENT>;

	class								Protocol : public boost::enable_shared_from_this<Protocol>
	{

		public:

			static boost::shared_ptr<Protocol> create(io_service &ios, Type type)
			{
				return boost::shared_ptr<Protocol>(new Protocol(ios, type));
			}

			static boost::shared_ptr<Protocol> create(io_service &ios, Type type,
													ip::tcp::endpoint endpoint,
													Net::Network<CLIENT> *clientNetwork)
			{
				return boost::shared_ptr<Protocol>(new Protocol(ios, type, endpoint, clientNetwork));
			}

			//OPERATIONS HANDLERS
			void 						handleReceivingHeader(const boost::system::error_code &err, size_t bytes);
			void 						handleReceivingData(const boost::system::error_code &err, size_t bytes);
			void 						handleSending(const boost::system::error_code &err, size_t bytes);

			//OPERATIONS
			void 						send(Net::Packet<Net::Type::CLIENT> packet);
			void 						send(Net::Packet<Net::Type::SERVER> packet);
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
			Protocol(io_service &ios, Type type, ip::tcp::endpoint endpoint, 
					Network<CLIENT> *clientNetwork);

			Packet<SERVER>				clientServerPacket_;
			Packet<CLIENT>				serverClientPacket_;
			ClientServerData			clientPacket_;
			ServerClientData			serverPacket_;
			ip::tcp::socket				socket_;

			//PACKET
			Type						type_;
			std::vector<char>			headerIn_;
			std::vector<char>			dataIn_;
			std::string					headerOut_;
			std::string					dataOut_;

			ip::tcp::endpoint			endpoint_;
			Network<CLIENT>				*clientNetwork_;
			RSA							*rsaKeys_;
	};

};

#endif
