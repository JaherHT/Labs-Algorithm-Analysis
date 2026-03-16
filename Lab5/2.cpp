#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

int binarySearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int interpolationSearch(const vector<int>& arr, int key) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        long long pos = low + (((long long)(high - low) * (key - arr[low])) / (arr[high] - arr[low]));

        if (arr[pos] == key) return pos;
        if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    const int SIZE = 10000000;
    
    vector<int> arr(SIZE);

    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % (SIZE * 10); 
    }

    sort(arr.begin(), arr.end());

    int keyToFind = arr[SIZE / 2]; 

    // measure binary search time and interpolation search time
    auto startBin = high_resolution_clock::now();
    int binResult = binarySearch(arr, keyToFind);
    auto stopBin = high_resolution_clock::now();
    auto durationBin = duration_cast<nanoseconds>(stopBin - startBin);

    auto startInt = high_resolution_clock::now();
    int intResult = interpolationSearch(arr, keyToFind);
    auto stopInt = high_resolution_clock::now();
    auto durationInt = duration_cast<nanoseconds>(stopInt - startInt);

    if (binResult != -1) {
        cout << "Binary search found key at index " << binResult 
             << " in " << durationBin.count() << " nanoseconds." << endl;
    } else {
        cout << "Key not found." << endl;
    }

    if (intResult != -1) {
        cout << "Interpolation search found key at index " << intResult 
             << " in " << durationInt.count() << " nanoseconds." << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}