#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check left child greater than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // check right child greater than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // if not the root, swap and continue filtering down
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();

    // start from last non-leaf node and heapify up to the root
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    std::vector<int> data = {4, 10, 3, 5, 1, 8, 9, 7, 2, 6};

    buildMaxHeap(data);

    for (int val : data) {
        std::cout << val << " ";
    }
    std::cout << '\n';

    return 0;
}