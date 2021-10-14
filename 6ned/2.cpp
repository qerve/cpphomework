// плохая реализация

#include <iostream>
#include <string>

class Drob
{
private:
	int m_a;
	int m_b;
	int nod(int x, int y)
	{
		if (y == 0) return x;
		return nod(y, x % y);
	}

public:
	void input(int i, int j)
	{
		m_a = i;
		m_b = j;
	}
	
	void sum(int x)
	{
		m_a += (x * m_b);
	}

	void sub(int x)
	{
		m_a -= (x * m_b);
	}

	void mult(int x)
	{
		m_a *= x;
	}

	void div(int x)
	{
		m_b *= x;
	}

	int per()
	{
		return nod(m_a, m_b);
	}

	void reduct(int x)
	{
		m_a /= x;
		m_b /= x;
	}

	void srav(double x)
	{
		double a;
		double b;
		a = m_a;
		b = m_b;
		if (x > ((a * 1.0) / b)) { std::cout << "Дробь меньше числа" << std::endl; }
		if (x < ((a * 1.0) / b)) { std::cout << "Дробь больше числа" << std::endl; }
		if (x == ((a * 1.0) / b)) { std::cout << "Дробь равна числу" << std::endl; }
	}

	void show()
	{
		std::cout << "Текущая дробь: " << m_a << "/" << m_b << std::endl;
	}

};

int main()
{
	std::cout << "Введите числитель и знаменатель дроби" << std::endl;
	int p, q, m, l, c;
	std::cin >> p >> q;
	Drob uwu;
	uwu.input(p, q);
	do
	{
		uwu.reduct(uwu.per());
		uwu.show();
		std::cout << "Выберите номер операции с дробью: " << std::endl << "1 - сложение \n2 - вычитание\n3 - умножение\n4 - деление\n5 - для сравнения\n6 - для выхода" << std::endl;
		std::cin >> m;
		switch (m)
		{
		case 1:
			std::cout << "Введите число:" << std::endl;
			std::cin >> l;
			uwu.sum(l);
			break;
	
		case 2:
			std::cout << "Введите число:" << std::endl;
			std::cin >> l;
			uwu.sub(l);
			break;	

		case 3:
			std::cout << "Введите число:" << std::endl;
			std::cin >> l;
			uwu.mult(l);
			break;

		case 4:
			std::cout << "Введите число:" << std::endl;
			std::cin >> l;
			uwu.div(l);
			break;

		case 5:
			std::cout << "Введите число:" << std::endl;
			std::cin >> l;
			uwu.srav(l);
			break;

		default:
			std::cout << "--->" << std::endl;

		std::cout << "Закончить? (1 - да)" << std::endl;
		std::cin >> c;
		}
	} while (c != 1);
	
	return 0;
}
