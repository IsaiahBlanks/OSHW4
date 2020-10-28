#include <iostream>
#include <array>

void clearArray(int *arrParam, int size) {
    for (int k = 0; k < size; k++) {
        *(arrParam + k) = 0;
    }
}

int* getFullArray(int size) {
    int* retArr = new int[size];
    for (int i = 0; i < size; i++) {
        *(retArr + i) = rand() % 100;
    }
    return retArr;
}

void readTheArray(int * theArray, int size) {
    int* newArray = new int[size];
    for (int i = 0; i < size; i++) {
        *(newArray + i) = theArray[i];
        std::cout << newArray[i] << " ";
    }
}

void insertIntoArray(int* arrParam, int index, int val) {
    *(arrParam + index) = val;
}

int main()
{
    //Question 1

    std::cout << "100 numbers using []\n";

    //fill array with 100 random numbers using [] notation
    int arr[100] = {};
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            std::cout << "\n";  //for printing a nice grid
        }

        arr[i] = rand() % 100; //sets arr[i] equal to random number 0-999
        std::cout << arr[i] << " ";
    }

    std::cout << "\n\n100 numbers using *\n";

    int* arr2 = new int[100];
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            std::cout << "\n";  //for printing a nice grid
        }

        *(arr2 + i) = rand() % 100;
        std::cout << arr2[i] << " ";
    }

    //Question 2

    std::cout << "\n\nFunction to clear array\nStarting array: \n";

    int arr3[5] = { 4, 9, 11, 54, 2 };

    for (int num : arr3) {
        std::cout << num << " ";
    }

    clearArray(arr3, 5);

    std::cout << "\nAfter clearing:\n";

    for (int num : arr3) {
        std::cout << num << " ";
    }

    //Question 3

    std::cout << "\n\nRandom array of specified size:\n";

    int * arr4 = getFullArray(30);
    for (int i = 0; i < 30; i++) {
        std::cout << arr4[i] << " ";
    }

    //Question 4

    std::cout << "\n\nCopying last array to new array:\n";

    readTheArray(arr4, 30);

    //Question 5
    std::cout << "\n\nInserting into an array:\n";

    int* arr5 = new int[]{ 1, 2, 3, 4 };
    insertIntoArray(arr5, 4, 5);
    for (int i = 0; i < 5; i++) {
        std::cout << arr5[i] << " ";
    }

    //Question 6
    
}

