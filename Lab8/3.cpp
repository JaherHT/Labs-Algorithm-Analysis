#include <iostream>
#include <vector>
#include <algorithm>

void distributionCountingSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // find bounds
    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    // allocarte count
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    // offset by min_val
    for (size_t i = 0; i < arr.size(); i++) {
        count[arr[i] - min_val]++;
    }

    // count[i] is the total number of elements less than or equal to i
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // distribute the elements into the output array. Iterate in reverse
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    // move the sorted data back to the original array.
    arr = std::move(output);
}

int main() {
    std::vector<int> data = {4, 2, 2, 8, 3, 3, 1, -5, 8, -2};
    
    std::cout << "Original array: ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    distributionCountingSort(data);

    std::cout << "Sorted array:   ";
    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}

// In comparison with counting sort (O(n^2)), distribution counting sort has a time complexity of O(n+k) where k is the range of the input. 
// It is more efficient when the range is small compared to the number of elements.
// However, allocating the count array in memmory can be inefficient if the range is large.