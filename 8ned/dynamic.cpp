#include <iostream>

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

template <typename T>
void heapSort(T* arr, size_t n, bool flag = true) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, flag);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0, flag);
    }
}

template <typename T>
void printArray(T arr[], int n) 
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() 
{
    std::cout << "Отсортировать по возрастанию или убыванию?\n1 - по возрастанию, 0 - по убыванию." << std::endl;
    int optiom;
    std::cin >> optiom;
    size_t size;
    std::cin >> size;
    int* arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = int(size - i);
    }
    double* epp = new double[size];
    for (size_t i = 0; i < size; ++i) {
        epp[i] = double(1.0/ (size - i + 1));
    }
    printArray(arr, size);
    heapSort(arr, size, bool(optiom));
    printArray(arr, size);

    printArray(epp, size);
    heapSort(epp, size, bool(optiom));
    printArray(epp, size);
    delete[] arr;
    delete[] epp;

    return 0;
}

