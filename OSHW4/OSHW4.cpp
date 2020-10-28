#include <iostream>
#include <array>

int main()
{
    std::cout << "100 numbers using []\n";

    //fill array with 100 random numbers using [] notation
    int arr[100] = {};
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            std::cout << "\n";  //for printing a nice grid
        }

        arr[i] = rand() % 1000; //sets arr[i] equal to random number 0-999
        std::cout << arr[i] << " ";
    }

    std::cout << "\n100 numbers using *\n";

    int* arr2 = new int[100];
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            std::cout << "\n";  //for printing a nice grid
        }

        *(arr2 + i) = rand() % 1000;
        std::cout << arr2[i] << " ";
    }
}
