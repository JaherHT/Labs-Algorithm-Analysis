#include <iostream>
#include <vector>

void comparisonCountingSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    // store number of smaller elements
    std::vector<int> count(n, 0);
    
    // holdthe sorted output
    std::vector<int> sortedArr(n);

    // compare pairs once
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                count[j]++;
            } else {
                count[i]++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        sortedArr[count[i]] = arr[i];
    }

    // copy sorted to original array
    arr = std::move(sortedArr); 
}

int main() {
    std::vector<int> data = {62, 31, 84, 96, 19, 47};
    
    std::cout << "Original array: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    comparisonCountingSort(data);

    std::cout << "Sorted array:   ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}