#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

char name[50];
std::mutex mute;

void read_data_until(boost::asio::ip::tcp::socket & socket)
{
	while(true){
		boost::asio::streambuf buffer;
		std::string message;
		mute.lock();
		boost::asio::read_until(socket, buffer, '!');
		mute.unlock();
		std::istream input_stream(&buffer);
		std::getline(input_stream, message, '!');
		std::cout << message << std::endl;
	}

}

void write_data(boost::asio::ip::tcp::socket& socket)
{
	std::string message;
	while(message != "Пока") 
    {
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
	std::string raw_ip_address = "127.0.0.1";
	auto port = 3333;
	const std::size_t size = 30;

	try
	{
		boost::asio::ip::tcp::endpoint endpoint(
		boost::asio::ip::address::from_string(raw_ip_address), port);
		boost::asio::io_service io_service;

		boost::asio::ip::tcp::socket socket(io_service, endpoint.protocol());

		socket.connect(endpoint);

		std::cout << "Имя 2: ";
		std::cin.getline(name, 50);

            std::thread write{[&socket](){write_data(socket);}};
            std::thread read{[&socket](){read_data_until(socket);}};
			write.join();
			read.join();
	}

	catch (boost::system::system_error& e)
	{
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what() << std::endl;
		return e.code().value();
	}

	return 0;
}
