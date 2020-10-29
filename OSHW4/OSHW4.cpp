#include <iostream>
#include <array>
#include <fstream>

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

void deleteFromArray(int* arrParam, int index, int size) {
    if (index < size && index >= 0) {
        for (int i = index; i < size; i++) {
            *(arrParam + i) = *(arrParam + i + 1);
        }
    }
}

void Alfa(int* arrParam, int size) {
    int min = arrParam[0];
    int max = 0;
    int sum = 0;
    int avg = 0;
    for (int i = 0; i < size; i++) {
        if (*(arrParam + i) < min) {
            min = *(arrParam + i);
        }
        if (*(arrParam + i) > max) {
            max = *(arrParam + i);
        }
        sum += *(arrParam + i);
    }
    avg = sum / size; //at this point, we should have the min, max, and avg of the array
    std::ofstream outfile;
    outfile.open("output.txt");
    outfile << "Array min: " << min << "\nArray max: " << max << "\nArray avg: " << avg;
    outfile.close();

}

void Bravo(int arr[][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }
    std::ofstream outfile;
    outfile.open("output2.txt");
    outfile << "2D Array total sum: "<< sum;
    outfile.close();
    std::cout << "2D Array total sum: " << sum;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int swap = arr[j];
            arr[j] = arr[i];
            arr[i] = swap;
        }
    }
    int swap = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = swap;
    return i + 1;

}

void Sort(int* arrayToSort, int low, int high) {
    if (low < high) {
        int index = partition(arrayToSort, low, high);
        Sort(arrayToSort, low, index - 1);
        Sort(arrayToSort, index + 1, high);
    }
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
    std::cout << "\n\nDeleting from an array:\n";
    
    int* arr6 = new int[] { 1, 2, 3, 4 };
    deleteFromArray(arr6, 2, 4);
    for (int i = 0; i < 4; i++) {
        std::cout << arr6[i] << " ";
    }

    //Question 7
    std::cout << "\n\nOutputting max, min, and avg of array to file\nSee output.txt\n";

    int* arr7 = new int[] { 1, 2, 3, 11, 22, 13212, 44 };
    Alfa(arr7, 7);

    //Question 8
    std::cout << "\n\nTotal of vals in a 3 x 3 array\n";

    int arr8[3][3] = { {1, 2, 5}, {6, 2, 11}, {153, 4, 90} };
    Bravo(arr8);

    //Question 9
    std::cout << "\n\nSorting an array using quicksort\n";

    int* arr9 = new int[] {54, 12, 5, 9, 11, 4, 2, 6, 7, 99, 3, 46, 29, 19, 109};
    int sizeOfArr9 = 15;

    std::cout << "\n\nBefore: \n";
    for (int i = 0; i < 15; i++) {
        std::cout << arr9[i] << " ";
    }

    Sort(arr9, 0, 16);

    std::cout << "\n\nAfter: \n";
    for (int i = 0; i < 15; i++) {
        std::cout << arr9[i] << " ";
    }
}

