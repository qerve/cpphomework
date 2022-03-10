#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void result(std::vector<int> p) 
{
    for (int n : p)
    {
        std::cout << n << " ";
    }
    std::cout << "\n" << std::endl;
}

int main()
{
// 1
    std::vector<int> p1 = { };
    int N = 10;
    for (int i; i < N; i++)
    {
        int number = 1 + rand() % 9;
        p1.push_back(number);
    }


result(p1);

// 2
    int add_number1, add_number2;
    std::cin >> add_number1;
    std::cin >> add_number2;
    p1.push_back(add_number1);
    p1.push_back(add_number2);

result(p1);

// 3
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(p1), std::end(p1), rng);

result(p1);

// 4
    auto p1_end = p1.end();
    for (auto it = p1.begin(); it != p1_end; ++it)
    {
        p1_end = std::remove(it + 1, p1_end, *it);
    }
    p1.erase(p1_end, p1.end());

result(p1);

// 5
    int count_3;
    for (int n : p1)
    {
        if (n % 3 == 0) {count_3 += 1;}
    }
    std::cout << count_3 << std::endl;

// 6
}



