/*
** Network.hh for cpp_spider in /home/tarkick/repos/cpp_spider/include
**
** Made by tarkick
** Login   <tarkick@epitech.net>
**
** Started on  Sat Nov 05 19:27:34 2016 tarkick
** Last update Wed Nov 09 02:28:47 2016 tarkick
*/

#ifndef NETWORK_HH_
# define NETWORK_HH_

# include <boost/asio.hpp>
# include <boost/bind.hpp>
# include <boost/archive/text_oarchive.hpp>
# include <boost/archive/text_iarchive.hpp>
# include <boost/date_time/posix_time/posix_time.hpp>
# include <iostream>
# include "NetworkProtocol.hh"
# include "NetworkOpcode.hh"

using namespace								std;
using namespace								boost;
using namespace								boost::asio;

namespace									Net
{

	template 								<Type>
	class									Network;

	template 								<>
	class									Network<SERVER>
	{

	public:
		Network(unsigned int port, Type type) : type_(type), endpoint_(ip::tcp::v4(),
												port), acceptor_(ios_, endpoint_)
		{
		}
		~Network() {}

		virtual void 						processingClient(boost::shared_ptr<Protocol>) = 0;

		//OPERATIONS HANDLERS
		void 								handleAccept(const boost::system::error_code &err,
											boost::shared_ptr<Protocol> connection)
		{
			if (!err)
			{
				cout << "Accepted" << endl;
				processingClient(connection);
				accept();
			}
			else
				cerr << "Denied" << endl;
		};

		//NETWORK
		void 								accept()
		{
			connections_.push_back(Protocol::create(acceptor_.get_io_service(), SERVER));
			acceptor_.async_accept(connections_.back()->getSocket(),
									boost::bind(&Network<SERVER>::handleAccept,
												this, boost::asio::placeholders::error,
												connections_.back()));
		};
		void 								send(boost::shared_ptr<Protocol> connection, Opcode::Server opcode)
		{
			connection->send(opcode);
		};
		void 								receive(boost::shared_ptr<Protocol> connection)
		{
			connection->receive();
		};

		void 								stop()
		{
		};
		void 								run()
		{
			ios_.run();
		};

		//GETTERS
		string								getIp() const
		{
			return							endpoint_.address().to_string();
		};
		Type								getType() const
		{
			return							type_;
		};

	private:
		io_service 							ios_;
		string								ip_;
		Type								type_;

		//NETWORK
		ip::tcp::endpoint 					endpoint_;
		ip::tcp::acceptor					acceptor_;
		vector<boost::shared_ptr<Protocol>>	connections_;

	};

	template 								<>
	class									Network<CLIENT>
	{

	public:
		Network(string ip, unsigned int port, Type type) : ip_(ip), type_(type), timer_(ios_),
															currentTries_(0), timeout_(10), maxTries_(3),
															endpoint_(ip::address::from_string(ip),
															port)
		{
		}
		Network(string ip, unsigned int port, Type type, unsigned int timeout) : ip_(ip), type_(type), timer_(ios_),
															currentTries_(0), timeout_(timeout), maxTries_(3),
															endpoint_(ip::address::from_string(ip),
															port)
		{
		}
		~Network() {}

		virtual void						processing() = 0;

		//HANDLERS
		void 								handleConnection(const boost::system::error_code &err)
		{
			if (!err)
			{
				cout << "Connected" << endl;
				processing();
			}
			else
			{
				cerr << "Connection failed, retrying in " << timeout_ << "s" << endl;
				if (currentTries_ == maxTries_)
				{
					connection_->timeout();
					timer_.expires_at(boost::posix_time::pos_infin);
			  	}
				currentTries_++;
				timer_.expires_from_now(posix_time::seconds(timeout_));
				timer_.async_wait(bind(&Network<CLIENT>::connect, this));
			}
		}

		//CONNECTION
		void 								connect()
		{
			connection_ = Protocol::create(ios_, CLIENT);
			connection_->getSocket().async_connect(endpoint_,
									bind(&Network<CLIENT>::handleConnection,
									this, _1)
								);
		}
		void 								send(Opcode::Client opcode)
		{
			connection_->send(opcode);
		};
		void 								send(Opcode::Client opcode, char key)
		{
			connection_->send(opcode, key);
		};
		void 								receive()
		{
			connection_->receive();
		}

		void 								run()
		{
			ios_.run();
		}

		//GETTERS
		string								getIp() const
		{
			return							ip_;
		};
		Type								getType() const
		{
			return							type_;
		};

		//SETTERS
		void 								setIp(const string &newIp)
		{
			ip_ = newIp;
		};

	private:
		io_service 							ios_;
		string								ip_;
		Type								type_;
		deadline_timer 						timer_;
		unsigned int 						currentTries_;

		//SETTINGS
		unsigned int						timeout_;
		unsigned int						maxTries_;

		//NETWORK
		ip::tcp::endpoint 					endpoint_;
		boost::shared_ptr<Protocol>			connection_;

	};

};
#endif
