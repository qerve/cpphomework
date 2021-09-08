#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	char prname[500], hik[7];
	int price = 0, temper = 0;
	cout << "Product's name: ";
	gets (prname);
	cout << "Product's price: ";
	cin >> price;
	cout << "Is cash-back available for this product? (true/false) ";
	cin >> hik;
	cout << "Maximum storing temperature: ";
	cin >> temper;
	cout << prname << endl;
	cout.unsetf(ios::dec);
	cout.setf(ios::hex | ios::uppercase);
	cout << "Price:" << setfill ('.') << setw(19) << right << price << endl;
	cout.setf(ios::dec);
	cout << "Has cash-back:" << setfill ('.') << setw(11) << right << hik << endl;
	cout << "Max temperature:" << setfill ('.') << setw(7) << right << "+" << temper << endl;
	return 0;
}

