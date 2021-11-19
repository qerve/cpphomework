#include <iostream>

template<class T>
struct is_function;
template<typename>
struct is_function : std::false_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile> : std::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile> : std::true_type {};

struct A {
    int fun() const&;
};
 
template<typename>
struct PM_traits {};
 
template<class T, class U>
struct PM_traits<U T::*> {
    using member_type = U;
};
 
int f();
 
int main() 
{
    double fk();
    std::cout << std::boolalpha;
    std::cout << is_function<A>::value << '\n';
    std::cout << is_function<double(int)>::value << '\n';
    std::cout << is_function<decltype(fk)>::value << '\n';
    std::cout << is_function<int>::value << '\n';
    using T = PM_traits<decltype(&A::fun)>::member_type; // T is int() const&
    std::cout << is_function<T>::value << '\n';
    return 0;
}

