#include <iostream>
#include <chrono>
#include <stack>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void hanoi_recursive(int n, int start, int end) {
    if (n == 1) {
        // cout << start << " -> " << end << "\n";
        return;
    }
    int other = 6 - (start + end);
    hanoi_recursive(n - 1, start, other);
    // cout << start << " -> " << end << "\n";
    hanoi_recursive(n - 1, other, end);
}

struct Move {
    int n, start, end, other;
    bool is_base_move;
};

void hanoi_iterative(int total_disks, int start_rod, int end_rod) {
    stack<Move> s;
    int other_rod = 6 - (start_rod + end_rod);
    s.push({total_disks, start_rod, end_rod, other_rod, false});

    while (!s.empty()) {
        Move current = s.top();
        s.pop();

        if (current.n == 1 || current.is_base_move) {
            // cout << current.start << " -> " << current.end << "\n";
        } else {
            s.push({current.n - 1, current.other, current.end, current.start, false});
            s.push({current.n, current.start, current.end, current.other, true});
            s.push({current.n - 1, current.start, current.other, current.end, false});
        }
    }
}

int main() {
    cout << "\tn | Recursive time (us) | Iterative time (us)\n";
    for (int n = 1; n <= 25; n++) {
        
        auto t_start_rec = high_resolution_clock::now();
        hanoi_recursive(n, 1, 3);
        auto t_finish_rec = high_resolution_clock::now();
        auto duration_rec = duration_cast<microseconds>(t_finish_rec - t_start_rec).count();
        
        auto t_start_iter = high_resolution_clock::now();
        hanoi_iterative(n, 1, 3);
        auto t_finish_iter = high_resolution_clock::now();
        auto duration_iter = duration_cast<microseconds>(t_finish_iter - t_start_iter).count();
        
        cout << setw(9) << n << " | " 
             << setw(19) << duration_rec << " | " 
             << setw(19) << duration_iter << "\n";
    }
    
    return 0;
}