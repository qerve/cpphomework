#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	double x = 0, key = 0;
	vector <double> vec;
	cout << "Введите количество элементов массива:" << endl;
	cin >> n;
	cout << "Введите поочередно элементы отсортированного массива:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	}  // импорт завершен
	int middle = (n-1)/2, left = 0, right = n-1;
	cout << "Введите искомую переменную:" << endl;
	cin >> key;
	while (left <= right) {
		middle = (left + right) / 2;
		if (vec[middle] == key) {
			cout << "Индекс искомого элемента равен " << middle << endl;
			break;
		}
		if (vec[middle] > key) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
		if (left >= right) {
			cout << "Такой элемент отсутствует в массиве." << endl;
			break;
		}
	}
	return 0;
}

