#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;
using namespace std::chrono;

vector<long long> linear_congruential(int n, long long m, long long seed, long long a, long long b) {
    vector<long long> r(n);
    
    long long r_i = seed;
    
    for (int i = 0; i < n; i++) {
        r_i = (a * r_i + b) % m;
        r[i] = r_i;
    }
    
    return r;
}

int main() {
    long long m = pow(2, 31); 
    long long seed = time(0); 
    long long a = 0.5 * m;    
    long long b = 1;          

    cout << "\t     n | Execution Time (us)\n";

    for (int n = 1000000; n <= 10000000; n += 1000000) {
        
        auto t_start = high_resolution_clock::now();
        linear_congruential(n, m, seed, a, b);
        auto t_finish = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(t_finish - t_start).count();

        cout << setw(14) << n << " | " << setw(19) << duration << "\n";
    }

    return 0;
}