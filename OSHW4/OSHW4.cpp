#include <iostream>
#include <array>
#include <fstream>
#include <vector>

using namespace std;

class Student {
public:
    string name = "";
    int IDNumber = -1;
    int* grades;

    Student() {
        grades = new int[4]{ 0, 0, 0, 0 };
    }

    string getName() {
        return name;
    }

    void setName(string n) {
        name = n;
    }

    int getID() {
        return IDNumber;
    }

    void setID(int id) {
        IDNumber = id;
    }

    void setGrades(int* g) {
        grades = g;
    }

    int* getGrades() {
        return grades;
    }
};

class Ticket {

private:
    static int Counter;
public: 
    int IDNumber = -1;
    enum TicketType { Parking_Violation, Moving_Violation, General_Misconduct };
    TicketType type;

    int getID() {
        return IDNumber;
    }

    void setID(int id) {
        this->IDNumber = id;
    }

    TicketType getType() {
        return type;
    }

    void setType(TicketType t) {
        this->type = t;
    }

    static string ToString() {
        return "The fine for this ticket is: " + rand() % 1000;
    }
    
    int getCounter() {
        return Counter;
    }

    Ticket() {
        Counter++;
    }

};
int Ticket::Counter = 0;

class Book {
public:
    string bookName;
    string author;
    int numPages;
    int numChapters;
    string chapters[];

    //constructor
    Book(const string name, const string auth, const int pages, const string chap[], const int chapNum) {
        this->bookName = name;
        this->author = auth;
        this->numPages = pages;
        for (int i = 0; i < chapNum; i++) {
            this->chapters[i] = chap[i];
        }
        this->numChapters = chapNum;
    }

    //destructor
    ~Book() {
        delete[] chapters;
    }

    //copy constructor
    Book(const Book& otherBook) :
        Book(otherBook.bookName, otherBook.author, otherBook.numPages, otherBook.chapters, otherBook.numPages) {
    };
    
    //copy assignment
    Book& operator=(const Book& otherBook) {
        if (this == &otherBook) return *this;
        bookName = otherBook.bookName;
        author = otherBook.author;
        numPages = otherBook.numPages;
        for (int i = 0; i < otherBook.numChapters; i++) {
            chapters[i] = otherBook.chapters[i];
        }
        numChapters = otherBook.numChapters;
    }

    Book(Book&& otherBook) noexcept
        : bookName{ otherBook.bookName }
          {

    }


    //move assignment
    Book& operator=(Book&& otherBook) noexcept {
        std::swap(bookName, otherBook.bookName);
        std::swap(author, otherBook.author);
        std::swap(numPages, otherBook.numPages);
        std::swap(numChapters, otherBook.numChapters);
        std::swap(chapters, otherBook.chapters);
        return *this;
    }
};

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
        cout << newArray[i] << " ";
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
    ofstream outfile;
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
    ofstream outfile;
    outfile.open("output2.txt");
    outfile << "2D Array total sum: "<< sum;
    outfile.close();
    cout << "2D Array total sum: " << sum;
}

int reversePartition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] > pivot) {
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

void reverseSort(int* arrayToSort, int low, int high) {
    if (low < high) {
        int index = reversePartition(arrayToSort, low, high);
        reverseSort(arrayToSort, low, index - 1);
        reverseSort(arrayToSort, index + 1, high);
    }
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
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

void sort(int* arrayToSort, int low, int high) {
    if (low < high) {
        int index = partition(arrayToSort, low, high);
        sort(arrayToSort, low, index - 1);
        sort(arrayToSort, index + 1, high);
    }
}

int binaryArraySearch(int arrayToSearch[], int low, int high, int num) {
    int iterations = 1;
    while (low <= high) {
        cout << "\nIteration: " << iterations;
        int mid = (low + (high - 1)) / 2;

        if (arrayToSearch[mid] == num) {
            return mid;
        }
        if (arrayToSearch[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        iterations++;
    }

    return -1;
}

void printVector(vector<int> v) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }
}

int main()
{
    //Question 1

    cout << "100 numbers using []\n";

    //fill array with 100 random numbers using [] notation
    int arr[100] = {};
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            cout << "\n";  //for printing a nice grid
        }

        arr[i] = rand() % 100; //sets arr[i] equal to random number 0-999
        cout << arr[i] << " ";
    }

    cout << "\n\n100 numbers using *\n";

    int* arr2 = new int[100];
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            cout << "\n";  //for printing a nice grid
        }

        *(arr2 + i) = rand() % 100;
        cout << arr2[i] << " ";
    }

    //Question 2

    cout << "\n\nFunction to clear array\nStarting array: \n";

    int arr3[5] = { 4, 9, 11, 54, 2 };

    for (int num : arr3) {
        cout << num << " ";
    }

    clearArray(arr3, 5);

    cout << "\nAfter clearing:\n";

    for (int num : arr3) {
        cout << num << " ";
    }

    //Question 3

    cout << "\n\nRandom array of specified size:\n";

    int * arr4 = getFullArray(30);
    for (int i = 0; i < 30; i++) {
        cout << arr4[i] << " ";
    }

    //Question 4

    cout << "\n\nCopying last array to new array:\n";

    readTheArray(arr4, 30);

    //Question 5
    cout << "\n\nInserting into an array:\n";

    int* arr5 = new int[]{ 1, 2, 3, 4 };
    insertIntoArray(arr5, 4, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr5[i] << " ";
    }

    //Question 6
    cout << "\n\nDeleting from an array:\n";
    
    int* arr6 = new int[] { 1, 2, 3, 4 };
    deleteFromArray(arr6, 2, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr6[i] << " ";
    }

    //Question 7
    cout << "\n\nOutputting max, min, and avg of array to file\nSee output.txt\n";

    int* arr7 = new int[] { 1, 2, 3, 11, 22, 13212, 44 };
    Alfa(arr7, 7);

    //Question 8
    cout << "\n\nTotal of vals in a 3 x 3 array\n";

    int arr8[3][3] = { {1, 2, 5}, {6, 2, 11}, {153, 4, 90} };
    Bravo(arr8);

    //Question 9
    cout << "\n\nSorting an array using quicksort\n";

    int* arr9 = new int[] {54, 12, 5, 9, 11, 4, 2, 6, 7, 99, 3, 46, 29, 19, 109};
    int sizeOfArr9 = 15;

    cout << "\n\nBefore: \n";
    for (int i = 0; i < 15; i++) {
        cout << arr9[i] << " ";
    }

    reverseSort(arr9, 0, 14);

    cout << "\n\nAfter: \n";
    for (int i = 0; i < 15; i++) {
        cout << arr9[i] << " ";
    }

    //Question 10

    cout << "\n\nArray of 100 random numbers\n";

    //fill array with 100 random numbers using [] notation
    int arr10[100] = {};
    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
            cout << "\n";  //for printing a nice grid
        }

        arr10[i] = rand() % 1000; //sets arr[i] equal to random number 0-999
        cout << arr10[i] << " ";
    }

    sort(arr10, 0, 99);
    cout << "\n\nAfter sorting: \n";
    for (int i = 0; i < 100; i++) {
        cout << arr10[i] << " ";
    }


    cout << "\n\nSearching...";
    int searchResult = binaryArraySearch(arr10, 0, 99, 476);

    cout << "\n\nFinished! Result: ";
    cout << searchResult;

    //Question 11
    cout << "\n\nArray of 10 random numbers using range-based for loop:\n";
    int arr11[10] = {};
    for (int i : arr11) {
        i = rand() % 1000; //sets arr[i] equal to random number 0-999
        cout << i << " ";
    }

    //Question 12
    vector<int> v;
    for (int i = 0; i < 20; i++) {
        v.push_back(rand() % 100);
    }

    //Question 13
    cout << "\n\nPrinting a vector containing 20 random numbers:\n";
    printVector(v); //prints contents of vector<int> using iterator

    //Question 14
    Student student1;
    Student student2;
    student1.setID(1);
    student1.setName("bob");
    student2.setID(2);
    student2.setName("jim");
    student1.setGrades(new int[4]{ 80, 90, 70, 10 });
    int* gradesArr1 = student1.getGrades();
    int* gradesArr2 = student2.getGrades();

    cout << "\n\nStudent 1 grades: \n";
    for (int i = 0; i < 4; i++) {
        cout << gradesArr1[i] << " ";
    }
    cout << "\n\nStudent 2 grades: \n";
    for (int i = 0; i < 4; i++) {
        cout << gradesArr2[i] << " ";
    }

    //Question 15
    Ticket ticket1;
    Ticket ticket2;
    ticket1.ToString();
    ticket2.ToString();

    cout << "\n\nNumber of Tickets initialized: \n";
    cout << ticket1.getCounter();
}

