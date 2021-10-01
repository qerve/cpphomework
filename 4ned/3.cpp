#include <iostream>
#include <iostream>

struct Time
{
	unsigned int year : 12;
	unsigned short month : 4;
	unsigned short day : 5;
	unsigned short hour : 5;
	unsigned short minutes : 6;
	unsigned short seconds : 6;
	unsigned short mseconds : 10;
};

int main()
{
	Time Asket = { 2021, 9, 20, 15, 24, 38, 232 };
	std::cout << Asket.year << "-" << Asket.month << "-" << Asket.day << std::endl << Asket.hour << ":" << Asket.minutes << ":" << Asket.seconds << "." << Asket.mseconds << std::endl;
	
	return 0;
}

struct Time
{
	unsigned int year : 12;
	unsigned short month : 4;
	unsigned short day : 5;
	unsigned short hour : 5;
	unsigned short minutes : 6;
	unsigned short seconds : 6;
	unsigned short mseconds : 10;
};

int main()
{
	Time Asket = { 2021, 9, 20, 15, 24, 38, 232 };
	std::cout << Asket.year << "-" << Asket.month << "-" << Asket.day << std::endl << Asket.hour << ":" << Asket.minutes << ":" << Asket.seconds << "." << Asket.mseconds << std::endl;
	
	return 0;
}
