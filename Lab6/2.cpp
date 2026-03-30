#include <iostream>
#include <vector>
#include <string>

struct Order {
    int price;
    std::string id;
};

// Utility function to print the order queue
void printOrders(const std::vector<Order>& arr) {
    for (const auto& order : arr) {
        std::cout << "[" << order.price << ", " << order.id << "]  ";
    }
    std::cout << "\n";
}

void merge(std::vector<Order>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Order> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;    
    int j = 0;    
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i].price <= R[j].price) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<Order>& arr, int left, int right) {
    if (left >= right) {
        return; // base case
    }
    
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void printVector(const std::vector<Order>& arr) {
    for (const auto& order : arr) {
        std::cout << "[" << order.price << ", " << order.id << "]  ";
    }
    std::cout << "\n";
}

int main() {
    // experiment with orders at the same price
    // Order_A arrives before Order_C
    std::vector<Order> orderQueue = {
        {50, "Order_A"}, 
        {40, "Order_B"}, 
        {50, "Order_C"}, 
        {30, "Order_D"}
    };
    
    std::cout << "Original Order Queue (By Arrival):\n";
    printOrders(orderQueue);

    // Sort the queue by price
    mergeSort(orderQueue, 0, orderQueue.size() - 1);

    std::cout << "\nSorted Order Queue (By Price):\n";
    printOrders(orderQueue);
    
    bool isStable = true;
    for (size_t i = 0; i < orderQueue.size() - 1; i++) {
        if (orderQueue[i].price == 50 && orderQueue[i+1].price == 50) {
            if (orderQueue[i].id == "Order_A" && orderQueue[i+1].id == "Order_C") {
                std::cout << "STABLE. Order_A executed before Order_C.\n";
            } else {
                std::cout << "UNSTABLE. Order was lost.\n";
                isStable = false;
            }
        }
    }

    return 0;
}