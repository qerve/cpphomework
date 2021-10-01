#include <iostream>

enum Moms
{
	JAN = 31,
	FEB = 28,
	MAR = 31,
	APR = 30,
	MAY = 31,
	JUN = 30,
	JUL = 31,
	AUG = 31,
	SEP = 30,
	OCT = 31,
	NOV = 30,
	DEC = 31
};

void vivod(int x)
{
	std::cout << "Вот сколько дней в указанном месяце:\n";
	switch (x)
	{
		case 1:
			std::cout << JAN;
			break;
		case 2:
			std::cout << FEB;
			break;
		case 3:
			std::cout << MAR;
			break;
		case 4:
			std::cout << APR;
			break;
		case 5:
			std::cout << MAY;
			break;
		case 6:
			std::cout << JUN;
			break;
		case 7:
			std::cout << JUL;
			break;
		case 8:
			std::cout << AUG;
			break;
		case 9:
			std::cout << SEP;
			break;
		case 10:
			std::cout << OCT;
			break;
		case 11:
			std::cout << NOV;
			break;
		case 12:
			std::cout << DEC;
			break;
		default:
			std::cout << "Ты че?";
	}
}

int main()
{
	int x = 0;
	std::cout << "Введите номер месяца:\n";
	std::cin >> x;
	vivod(x);

	return 0;
}
