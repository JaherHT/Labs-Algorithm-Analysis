#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

long long knapsackExhaustive(int W, const vector<int>& wt, const vector<int>& val, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (wt[n - 1] > W) {
        return knapsackExhaustive(W, wt, val, n - 1);
    } 
    else {
        long long included = val[n - 1] + knapsackExhaustive(W - wt[n - 1], wt, val, n - 1);
        long long excluded = knapsackExhaustive(W, wt, val, n - 1);
        return max(included, excluded);
    }
}

int main() {
    // random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> weight_dist(1, 100);
    uniform_int_distribution<> value_dist(10, 500);

    const double MAX_TIME_SECONDS = 600.0;

    cout << left << setw(10) << "n" 
         << setw(20) << "Time"
         << setw(15) << "Max Value" << endl;

    int n = 4;
    while (true) {
        vector<int> weights(n);
        vector<int> values(n);
        int total_weight = 0;

        for (int i = 0; i < n; ++i) {
            weights[i] = weight_dist(gen);
            values[i] = value_dist(gen);
            total_weight += weights[i];
        }

        int W = total_weight / 2;

        auto start = high_resolution_clock::now();

        long long max_val = knapsackExhaustive(W, weights, values, n);

        auto stop = high_resolution_clock::now();
        duration<double> time_taken = stop - start;

        cout << left << setw(10) << n 
             << fixed << setprecision(6) << setw(20) << time_taken.count() 
             << setw(15) << max_val << endl;

        if (time_taken.count() > MAX_TIME_SECONDS) {
            cout << "Execution time exceeded 10 minutes." << endl;
            cout << "Largest n within 10 minutes of execution = " << n - 1 << "." << endl;
            break;
        }

        n++;
    }

    return 0;
}