#ifndef NETWORKPACKETDATA_HH_
# define NETWORKPACKETDATA_HH_

# include <boost/asio.hpp>

namespace 						Net
{

	using namespace				boost;
	using namespace				boost::asio;

	struct						Data
	{
		uint8_t					type;
		char 					payload[1024];

		template 				<typename Archive>
		void 					serialize(Archive& ar,
			const unsigned int version)
		{
			(void)version;
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
			(void)version;
			ar 					&endianness;
			ar 					&spider;
			ar 					&is_complete;
			ar 					&opcode;
			ar 					&data;
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
			(void)version;
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

};

#endif // !NETWORKPACKETDATA_HH_
