#include <iostream>

constexpr bool roar(int number)
{
    if (number == 2 || number == 3)
    {
        return true;
    }

    if ( (number * number) % 24 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

constexpr int prime(int n)
{
    int i = 1;
    int x = 1;
    while (i <= n)
    {
        x += 1;
        if (roar(x)) { i += 1; }
    }
    return x;
}

int main()
{
    std::cout << prime(1) << std::endl;  // 2
    std::cout << prime(2) << std::endl;  // 3
    std::cout << prime(3) << std::endl;  // 5
    std::cout << prime(4) << std::endl;  // 7
    std::cout << prime(5) << std::endl;  // 11
    return 0;
}
