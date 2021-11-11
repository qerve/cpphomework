#include <iostream>
#include <new>

//пока не работает, проблемы с clang - скоро пофикшу
template<typename T, typename... Args>
auto coll(Args... args)
{
    int n = sizeof...(args);
    T *pala = new T[n] {args...};
    return pala;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int opo[] = { 2, 1 ,3 };
    int *p = coll<int>(opo);
    printArray(p, 3);
    //std::cout << coll<int>(opo) << std::endl;
    return 0;
}
