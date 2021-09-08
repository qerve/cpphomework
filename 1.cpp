#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double D = 0, a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	cout << "Введите значения коэффициентов для решения квадратного уравнения вида ax^2 + bx + c:\na = ";
	cin >> a;
	cout << "\nb = ";
	cin >> b;
	cout << "\nc = ";
	cin >> c;
	D = b*b*1.0 - 4.0*a*c;
	if (D >= 0) {
		x1 = -(b*1.0 / (2.0*a)) - sqrt(b*b*1.0 - 4.0*a*c)/(2.0*a);
		x2 = -(b*1.0 / (2.0*a)) + sqrt(b*b*1.0 - 4.0*a*c)/(2.0*a);
	}
	else {
	cout << "Корней нет" << endl;
	}
	cout << x1 << endl << x2 << endl;
	return 0;
}
