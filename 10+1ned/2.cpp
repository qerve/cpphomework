#include <iostream>

template <class T>
struct add_const { typedef const T type; };

template <class T>
struct remove_const { typedef T type; };

class jojo
{
public:
    void m() const { std::cout << "Const\n"; }
    void n() volatile { std::cout << "Volatile\n"; }
};

int main()
{
    jojo{}.m();
    add_const<jojo>::type{}.m();
    typedef remove_const<const int>::type type1;
    jojo{}.n();
    add_const<jojo>::type{}.m();
    typedef remove_const<const int>::type type1;

    return 0;
}
