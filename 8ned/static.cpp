#include <iostream>
#include <algorithm>

template<typename T>
bool compare(T a, T b, bool flag)
{
    if (flag)
        return a > b;
    else
        return a < b;
}

template <typename T>
void heapify(T& arr, int n, int i, bool flag) 
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && compare(arr[l], arr[largest], flag))
        largest = l;

    if (r < n && compare(arr[r], arr[largest], flag))
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest, flag);
    }
}

template <typename T, size_t N>
void heapSort(T(&arr)[N], bool flag = true) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i, flag);

    for (int i = N - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0, flag);
    }
}

template <typename T >
void printArray(T  arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    std::cout << "Отсортировать по возрастанию или убыванию?\n1 - по возрастанию, 0 - по убыванию." << std::endl;
    int optiom;
    std::cin >> optiom;
    char epp[] = { 'a', 'y', 'e', 'c', 'g', 'u' };
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    heapSort(arr, bool(optiom));
    heapSort(epp, bool(optiom));
    printArray(arr, 6);  // int
    printArray(epp, 6);  // char
    //std::cout << bool(optiom);
    return 0;
}


