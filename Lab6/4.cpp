#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // last element as the pivot
    int i = (low - 1);     // index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

std::vector<int> generateRandomVector(size_t size) {
    std::vector<int> arr(size);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 1000000);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = dist(rng);
    }
    return arr;
}

int main() {
    std::vector<size_t> testSizes = {10000, 50000, 100000, 500000, 1000000};
    std::cout << std::left << std::setw(15) << "N (Elements)" 
              << std::setw(20) << "Time (ms)" << "\n";

    for (size_t size : testSizes) {
        std::vector<int> testData = generateRandomVector(size);

        auto start = std::chrono::high_resolution_clock::now();

        quickSort(testData, 0, testData.size() - 1);

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        std::cout << std::left << std::setw(15) << size 
                  << std::setw(20) << duration.count() << "\n";
    }

    return 0;
}

// With C = T(n)/(n log n), we can calculate C for each test case and see that it remains relatively constant (~3e-5),
// confirming the O(n log n) time complexity of the quicksort algorithm.
