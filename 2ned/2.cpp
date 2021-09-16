#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	double x;
	vector <double> vec;
	cout << "Введите количество элементов массива:" << endl;
	cin >> n;
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
	} // вектор готов
	for (int i = 1; i < n; i++) {
		for (int j = i; j != 0 && vec[j] < vec[j-1]; j--) {
			swap(vec[j], vec[j-1]);
		}
	}
	cout << "Отсортированный массив выглядит так:" << endl;
	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	return 0;
}

