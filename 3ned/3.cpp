#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	std::cout << "Введите число элементов массива:" << std::endl;
	int n = 0;
	std::cin >> n;
	std::vector <double> vec;
	vec.reserve(n);
	std::cout << "Введите элементы массива:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		double x = 0;
		std::cin >> x;
		vec.push_back(x);
	}
	
	std::sort(vec.begin(), vec.end(), [](double a, double b) {return (a > b); });
	std::cout << "Отсортированный массив по убыванию:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::sort(vec.begin(), vec.end(), [](double a, double b) {return (a < b); });
	std::cout << "Отсортированный массив по возрастанию:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << vec[i] << " ";
	}
	return 0;
}
