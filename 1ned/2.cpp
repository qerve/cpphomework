#include <iostream>

using namespace std;


int main() {
	double a = 0;
	char coil;
	const double joule = 4.1868;
	cout << "Перевод СГСЭ в СИ.\nВыберите что переводить:\n1.см -> м\n2.г -> кг\n3.эрг -> Дж\n4.дин/см^2 -> н/м^2\n5.кал -> Дж\n6.гс -> Т\nВыбор:";
	cin >> coil;
	cout << "Величина:";
	cin >> a;
	switch(coil) 
	{
		case '1':
			cout << "\n" << (0.01 * a) << endl;
			break;
		case '2':
			cout << "\n" << (0.001 * a) << endl;
			break;
		case '3':
			cout << "\n" << (0.0000001 * a) << endl;
			break;
		case '4':
			cout << "\n" << (0.1 * a) << endl;
			break;
		case '5':
			cout << "\n" << (joule * a) << endl;
			break;
		case '6':
			cout << "\n" << (0.0001 * a) << endl;
			break;
		default:
			cout << "\nФейспалм." << endl;
			break;
	}
	return 0;
}

