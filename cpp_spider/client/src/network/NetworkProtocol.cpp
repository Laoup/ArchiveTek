#include "Network.hh"
#include "NetworkProtocol.hh"

Net::Protocol::Protocol(io_service &ios, Type type) : socket_(ios), type_(type)
{
}

Net::Protocol::Protocol(io_service &ios, Type type, ip::tcp::endpoint endpoint,
						Net::Network<CLIENT> *clientNetwork) : socket_(ios), type_(type), 
																endpoint_(endpoint), clientNetwork_(clientNetwork)
{
}

//OPERATIONS HANDLERS
void 								Net::Protocol::handleReceivingHeader(const boost::system::error_code &err,
																		size_t bytes)
{
	if (!err)
	{
		size_t 						dataSize(0);

		std::cout << "Header received " << bytes << " bytes" << std::endl;
		std::istringstream 			is(std::string(headerIn_.begin(), headerIn_.end()));
		is >> std::hex >> dataSize;
		dataIn_.resize(dataSize);
		async_read(socket_, buffer(dataIn_),
				bind(&Protocol::handleReceivingData, this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
	}
	else
	{
		std::cout << "Connection lost" << std::endl;
		if (type_ == Net::CLIENT && !clientNetwork_->isTryingToConnect())
			clientNetwork_->connect();
	}
}

void 								Net::Protocol::handleReceivingData(const boost::system::error_code &err, size_t bytes)
{
	(void) socket;
	if (!err)
	{
		std::cout << "Received data " << bytes << " bytes" << std::endl;
		if (type_ == SERVER)
		{
			clientServerPacket_.deserialize(dataIn_);
			clientServerPacket_.print();
		}
		else
		{
			serverClientPacket_.deserialize(dataIn_);
			serverClientPacket_.print();
		}
		receive();
	}
	else
	{
		std::cout << "Connection lost" << std::endl;
		if (type_ == Net::CLIENT && !clientNetwork_->isTryingToConnect())
			clientNetwork_->connect();
	}

}

void 								Net::Protocol::handleSending(const boost::system::error_code &err,
																std::size_t bytes)
{
	if (!err)
	{
		std::cout << "Sended " << bytes << " bytes" << std::endl;
	}
	else
	{
		std::cout << "Connection lost" << std::endl;
		if (type_ == Net::CLIENT && !clientNetwork_->isTryingToConnect())
			clientNetwork_->connect();
	}
}

//OPERATIONS
void								Net::Protocol::send(Net::Packet<Net::Type::SERVER> packet)
{
	std::vector<const_buffer> 		buffers;

	packet.serialize();
	dataOut_ = packet.getData();
	headerOut_ = packet.getHeader();
	buffers.push_back(boost::asio::buffer(headerOut_));
	buffers.push_back(boost::asio::buffer(dataOut_));
	async_write(socket_, buffers,
		boost::bind(&Protocol::handleSending,
			this, boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void 								Net::Protocol::send(Net::Packet<Net::Type::CLIENT> packet)
{
	std::vector<const_buffer> 		buffers;

	packet.serialize();
	dataOut_ = packet.getData();
	headerOut_ = packet.getHeader();
	buffers.push_back(boost::asio::buffer(headerOut_));
	buffers.push_back(boost::asio::buffer(dataOut_));
	async_write(socket_, buffers,
		boost::bind(&Protocol::handleSending,
			this, boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void 								Net::Protocol::receive()
{
	(type_ == SERVER ? headerIn_.resize(17) : headerIn_.resize(10));
	async_read(socket_, buffer(headerIn_),
			bind(&Net::Protocol::handleReceivingHeader, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
}
