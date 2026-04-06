#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

// mat stores both L and U
void luDecomposition(std::vector<std::vector<double>>& mat, std::vector<int>& P) {
    int n = mat.size();
    
    // permutation vector
    for (int i = 0; i < n; ++i) {
        P[i] = i;
    }

    for (int k = 0; k < n; ++k) {
        int pivot_row = k;
        for (int i = k + 1; i < n; ++i) {
            if (std::abs(mat[i][k]) > std::abs(mat[pivot_row][k])) {
                pivot_row = i;
            }
        }

        if (pivot_row != k) {
            std::swap(mat[k], mat[pivot_row]);
            std::swap(P[k], P[pivot_row]);
        }

        // Gaussian elimination
        for (int i = k + 1; i < n; ++i) {
            mat[i][k] /= mat[k][k]; // stored in the lower triangular
            
            for (int j = k + 1; j < n; ++j) {
                mat[i][j] -= mat[i][k] * mat[k][j]; // upper triangular
            }
        }
    }
}

std::vector<double> luSolve(const std::vector<std::vector<double>>& LU, const std::vector<int>& P, const std::vector<double>& b) {
    int n = LU.size();
    std::vector<double> y(n), x(n);

    // forward substitution
    for (int i = 0; i < n; ++i) {
        y[i] = b[P[i]];
        for (int j = 0; j < i; ++j) {
            y[i] -= LU[i][j] * y[j];
        }
    }

    // backward substitution
    for (int i = n - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) {
            x[i] -= LU[i][j] * x[j];
        }
        x[i] /= LU[i][i];
    }

    return x;
}

int main() {
    // A
    std::vector<std::vector<double>> A = {
        { 2,  1, -1},
        {-3, -1,  2},
        {-2,  1,  2}
    };

    // b
    std::vector<double> b = {8, -11, -3};
    std::vector<int> P(A.size());

    // A into L and U
    luDecomposition(A, P);

    // solve for x
    std::vector<double> x = luSolve(A, P, b);

    std::cout << "Solution:\n";
    for (size_t i = 0; i < x.size(); ++i) {
        std::cout << "x_" << i << " = " << x[i] << '\n';
    }

    return 0;
}