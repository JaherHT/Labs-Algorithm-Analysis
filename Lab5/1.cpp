#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSort(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    
    const int SIZE = 15;
    char arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = 'A' + (rand() % 26);
    }

    cout << "Unsorted array: \n";
    printArray(arr, SIZE);

    insertionSort(arr, SIZE);

    cout << "\nSorted array: \n";
    printArray(arr, SIZE);

    return 0;
}