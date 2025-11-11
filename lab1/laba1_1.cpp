#include <iostream>
#include <array>

int main() {
    const int SIZE = 10;
    std::array<double, SIZE> arr;
    for (int i = 0; i < SIZE; i++) arr[i] = i + 1.1;
    double* baseAddress = arr.data();
    std::cout << "Адрес начала массива: " << static_cast<void*>(baseAddress) << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << "Элемент " << i << " = " << arr[i]
                  << ", адрес: " << static_cast<void*>(&arr[i])
                  << ", смещение: " << (&arr[i] - baseAddress) * sizeof(double) << " байт" << std::endl;
    return 0;
}