#include <iostream>

template <class T>
void heapify(T& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

template <class T>
void heapSort(T* arr, size_t n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    size_t size;
    std::cin >> size;
    int* arr = new int[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = int(size - i);
    }
    printArray(arr, size);
    heapSort(arr, size);
    printArray(arr, size);
    delete[] arr;

    return 0;
}
