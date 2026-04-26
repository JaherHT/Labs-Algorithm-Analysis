#include <iostream>

long long fibonacci(int n) {
    if (n < 0) {
        std::cerr << "n must be a non negative integer." << std::endl;
        return -1; 
    }
    
    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Recursive step
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    
    std::cout << "n: ";
    std::cin >> n;
    
    long long result = fibonacci(n);
    
    if (result != -1) {
        std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;
    }
    
    return 0;
}