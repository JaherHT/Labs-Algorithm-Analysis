#include <iostream>
#include <vector>
#include <iomanip>

// mat is N x (N+1) upper triangular augmented matrix
std::vector<double> backwardSubstitution(const std::vector<std::vector<double>>& mat) {
    int n = mat.size();
    std::vector<double> solution(n);

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        
        // substitute
        for (int j = i + 1; j < n; ++j) {
            sum += mat[i][j] * solution[j];
        }
        
        // isolate and solve
        solution[i] = (mat[i][n] - sum) / mat[i][i];
    }

    return solution;
}

int main() {
    // example
    std::vector<std::vector<double>> matrix = {
        { 2,    1,   -1,    8},
        { 0,  0.5,  0.5,    1},
        { 0,    0,   -1,   -2}
    };

    std::vector<double> result = backwardSubstitution(matrix);

    std::cout << "Solution:\n";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "x_" << i << " = " << result[i] << '\n';
    }

    return 0;
}