#include <iostream>

int main() {
    int u = 15;
    int v = 25;

    std::cout << "Original values: u = " << u << ", v = " << v << "\n\n";

    // bitwise XOR swap
    
    u = u ^ v;
    v = u ^ v;
    u = u ^ v;

    std::cout << "After swap:  u = " << u << ", v = " << v << "\n\n";
}