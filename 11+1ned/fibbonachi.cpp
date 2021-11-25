#include <iostream>

template <int n>
struct F
{
    static constexpr int value = F<n-1>::value + F<n-2>::value;
};

template <>
struct F<0>
{
    static constexpr int value = 0;
};

template <>
struct F<1>
{
    static constexpr int value = 1;
};


int main()
{
    std::cout << F<7>::value << std::endl; // 13
    std::cout << F<8>::value << std::endl; // 21
    return 0;
}
