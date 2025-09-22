#include <bits/stdc++.h>
using namespace std;

void printSolution(const vector<float>& vec) {
    cout << "The solution is:" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "x[" << i + 1 << "] = " << vec[i] << endl;
    }
}

bool isDiagonallyDominant(const vector<vector<float>>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        float diagonal_element = abs(a[i][i]);
        float sum_of_row = 0;
        for (size_t j = 0; j < a.size(); ++j) {
            if (i != j) sum_of_row += abs(a[i][j]);
        }
        if (diagonal_element <= sum_of_row) return false;
    }
    return true;
}

int main() {
    int n = 3;
    vector<vector<float>> a = {
        {10, -1, 2},
        {-1, 11, -1},
        {2, -1, 10}
    };
    vector<float> b = {6, 25, -11};
    vector<float> x(n, 0);
    float allowed_error = 0.0001;
    int max_iterations = 25;

    if (!isDiagonallyDominant(a)) {
        cout << "WARNING: The matrix is not strictly diagonally dominant." << endl;
        cout << "The Gauss-Seidel method may not converge." << endl;
    }

    cout << "\n--- Iteration Process ---" << endl;

    int k;
    for (k = 0; k < max_iterations; ++k) {
        float max_error = 0.0;
        cout << "Iteration " << k + 1 << ": ";
        for (int i = 0; i < n; ++i) {
            float sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j) sum += a[i][j] * x[j]; // latest values are used
            }
            float temp = (b[i] - sum) / a[i][i];
            float current_error = fabs(temp - x[i]);
            if (current_error > max_error) max_error = current_error;
            x[i] = temp; // overwrite immediately
            cout << "x[" << i + 1 << "]=" << fixed << setprecision(5) << x[i] << " ";
        }
        cout << "| Error = " << max_error << endl;
        if (max_error < allowed_error) {
            cout << "\nConvergence achieved after " << k + 1 << " iterations." << endl;
            break;
        }
    }

    if (k == max_iterations) {
        cout << "\nMaximum iterations reached without converging to the desired tolerance." << endl;
    }

    cout << "\n------------------------------------" << endl;
    cout << fixed << setprecision(6);
    printSolution(x);
    cout << "------------------------------------" << endl;

    return 0;
}
