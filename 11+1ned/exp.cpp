#include <iostream>

int Fact(int x)
{
    int i = 1;
    int value = 1;
    while (i != x)
    {
        i += 1;
        value = value * i;
    }
    return value;
};

constexpr double F(int n)
{
    int x = 0;
    int xi = 1;
    double value = 1;
    while (x != n)
    {
        x += 1;
        xi = Fact(x);
        value += 1.0 / xi;
    }
    return value;
}

int main()
{
    std::cout << F(0) << std::endl;
    std::cout << F(1) << std::endl;
    std::cout << F(2) << std::endl;
    std::cout << F(23) << std::endl;
    return 0;
}
