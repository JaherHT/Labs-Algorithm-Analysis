#include <iostream>

int main() {
    int n = 100; // terms

    long long t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            std::cout << t1 << " ";
            continue;
        }
        if (i == 1) {
            std::cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        std::cout << nextTerm << " ";
    }
    return 0;
}