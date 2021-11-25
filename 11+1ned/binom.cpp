#include <iostream>

template <int k, int n>
struct Binom
{
    static constexpr int value = Binom<k, n-1>::value + Binom<k-1, n-1>::value;
};

template <int n>
struct Binom<n, 0>
{
    static constexpr int value = 0;
};

template <>
struct Binom<0, 0>
{
    static constexpr int value = 1;
};

template <int t>
struct Binom<t, t>
{
    static constexpr int value = 1;
};

template <int k>
struct Binom<0, k>
{
    static constexpr int value = 1;
};

int main()
{
    std::cout << Binom<2, 3>::value << std::endl;  // 3
    std::cout << Binom<1, 2>::value << std::endl;  // 2
    std::cout << Binom<5, 10>::value << std::endl;  // 252
    return 0;
}
