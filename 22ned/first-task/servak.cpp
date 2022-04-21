#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

char name[10];
std::mutex mute;

void read_data_until(boost::asio::ip::tcp::socket & socket)
{
	while(true)
    {
		boost::asio::streambuf buffer;
		boost::asio::read_until(socket, buffer, '!');
		std::string message;
		std::istream input_stream(&buffer);
		std::getline(input_stream, message, '!') ;
		std::cout << message << std::endl;  // return
	}
}


void write_data(boost::asio::ip::tcp::socket & socket)
{
	std::string message;
	while(message != "Пока") {
	getline(std::cin, message);
	std::string data = name;
	data += ": ";
	data += message;
	data += "!EOF";
	boost::asio::write(socket, boost::asio::buffer(data));
	}
}


int main()
{
	const std::size_t size = 100;
	auto port = 3333;
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address_v4::any(), port);
	boost::asio::io_service io_service;

	try
	{

		boost::asio::ip::tcp::acceptor acceptor(io_service, endpoint.protocol());
		acceptor.bind(endpoint);
		acceptor.listen(size);
		boost::asio::ip::tcp::socket socket(io_service);
		acceptor.accept(socket);

		std::cout << "Успех!" << std::endl;
		std::cout << "Укажите имя: ";
		std::cin.getline(name, 10);

            std::thread read{[&socket](){read_data_until(socket);}};
            std::thread write{[&socket](){write_data(socket);}};
			read.join();
			write.join();
	}
	catch (boost::system::system_error & e)
	{
		std::cout << e.what() << std::endl;
		return e.code().value();
	}
	return 0;
}
