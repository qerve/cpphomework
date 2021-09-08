#include <iostream>

using namespace std;

int main()
{
	int x = 9, y = 5;
	cout << "Введите поочередно значения x и y:" << endl;
	cin >> x >> y;
	x = x - y;  //x = 4
	y = y + x;  //y = 9
	x = y - x;  //x = 5
	cout << "x = " << x << endl << "y = " << y << endl;
	return 0;
}

