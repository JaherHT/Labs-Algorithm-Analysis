#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void forwardElimination(std::vector<std::vector<double>>& mat) {
    int n = mat.size();

    for (int k = 0; k < n; ++k) {
        int pivot_row = k;
        for (int i = k + 1; i < n; ++i) {
            if (std::abs(mat[i][k]) > std::abs(mat[pivot_row][k])) {
                pivot_row = i;
            }
        }

        if (pivot_row != k) {
            std::swap(mat[k], mat[pivot_row]);
        }

        // eliminate entries below the pivot
        for (int i = k + 1; i < n; ++i) {
            double factor = mat[i][k] / mat[k][k];
            for (int j = k; j <= n; ++j) {
                mat[i][j] -= factor * mat[k][j];
            }
        }
    }
}

int main() {
    // example
    std::vector<std::vector<double>> matrix = {
        { 2,  1, -1,   8},
        {-3, -1,  2, -11},
        {-2,  1,  2,  -3}
    };

    forwardElimination(matrix);

    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << std::setw(10) << val << " ";
        }
        std::cout << '\n';
    }

    return 0;
}