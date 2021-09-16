#include <iostream>
#include <vector>
#include <string>

using namespace std;

// По алгоритму Нидлмана-Вунша, но только для ч
int main()
{
	// Входные данные
	int n = 0, m = 0;
	cout << "Введите количество элементов 1ой и 2ой последовательности поочередно:" << endl;
	cin >> n;
	cin >> m;
	n = n + 2;
	m = m + 2;
	vector < vector <int> > a((n), vector <int> ((m)) );
	cout << "Введите элементы 1ой последовательности:" << endl;
	for (int i = 2; i < n; i++) {
        cin >> a[i][0];
	}
    cout << "Введите элементы 2ой последовательности:" << endl;
    for (int j = 2; j < m; j++)
		cin >> a[0][j];
    
    // Заполняем матрицу
    for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (a[i][0] == a[0][j]) {
				a[i][j] = a[i-1][j-1] + 1;
			}
			else {
				a[i][j] = max(a[i-1][j], a[i][j-1]);
			}
			
		}
	}
	
	// Соединяем
	int i = n - 1, j = m - 1, k = 0;
	vector <double> lcs;
	while (i >= 2 && j >= 2) {
		if (a[i][0] == a[0][j]) {
			lcs.push_back(a[i][0]);
			i = i - 1;
			j = j - 1;
			k = k + 1;
		}
		else if (a[i-1][j] > a[i][j-1]) {
			i = i - 1;
		}
		else {
			j = j - 1;
		}
	}
	
    // Вывод
    cout << "Совпадающая последовательность представлена ниже:" << endl;
    for (int i = k-1; i >= 0; i--)
    {
        cout << lcs[i] << " ";
    }
    
    cout << "\nЖелаете увидеть матрицу Нидлмана-Вунша?\nВведите 1 если хотите" << endl;
    int opt = 0;
    cin >> opt;
    if (opt == 1) {
		// Вывод матрицы
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
	else {
		cout << "Чел)";
	}
	return 0;
}

