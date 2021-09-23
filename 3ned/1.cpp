#include <iostream>

int fibb(int x)
{
	if ((x == 1) || (x == 2))
		{
			return 1;
		}
	else
		{
			return (fibb(x-1) + fibb(x-2));
		}
}

int main()
{
	int n;
	std::cout << "Введите номер искомого числа Фиббоначи:" << std::endl;
	std::cin >> n;
	std::cout << fibb(n);
	return 0;
}
