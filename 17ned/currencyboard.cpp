#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>
 
int main()
{
    double curr;
    std::string amount;
    std::cout << "Введите сумму в долларах: ";
    std::cin >> amount;
    std::cout << "Введите курс доллара: ";
    std::cin >> curr;
    std::istringstream in(amount);
    long double v1, v2;
    std::string v3;
    in.imbue(std::locale("en_US.UTF-8"));
    in >> std::get_money(v1) >> std::get_money(v2) >> std::get_money(v3, true);
    std::cout.imbue(std::locale("ru_RU.UTF-8"));
    v1 = v1 * curr;
    std::cout << "Сумма в рублях: " << std::put_money(v1, true);
}
