#include<bits/stdc++.h>
using namespace std;

void printSolution(const vector<float>& vec) {
    cout << "The solution is:" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "x[" << i + 1 << "] = " << vec[i] << endl;
    }
}

/**
 * @brief Checks if the matrix is diagonally dominant.
 * The Jacobi method is guaranteed to converge if the matrix is strictly diagonally dominant.
 * @param a The coefficient matrix.
 * @return True if the matrix is diagonally dominant, false otherwise.
 */
bool isDiagonallyDominant(const vector<vector<float>>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        float diagonal_element = abs(a[i][i]);
        float sum_of_row = 0;
        for (size_t j = 0; j < a.size(); ++j) {
            if (i != j) {
                sum_of_row += abs(a[i][j]);
            }
        }
        if (diagonal_element <= sum_of_row) {
            return false;
        }
    }
    return true;
}


int main() {
    // 1. Declare variables and read the order of the matrix
    int n;
    cout << "Enter the order of the matrix (n): ";
    cin >> n;

    vector<vector<float>> a(n, vector<float>(n));
    vector<float> b(n);
    vector<float> x(n, 0); // Current solution vector, initial guess is all zeros
    vector<float> x_new(n); // Stores the next iteration's values

    float allowed_error;
    int max_iterations;

    // 2. Read the coefficients of the matrix A
    cout << "\nEnter the coefficients of the matrix A row by row:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Enter coefficients for equation " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    // 3. Read the vector b
    cout << "\nEnter the constants of vector b:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "b[" << i + 1 << "]: ";
        cin >> b[i];
    }

    // Check for diagonal dominance
    if (!isDiagonallyDominant(a)) {
        cout << "\nWARNING: The matrix is not strictly diagonally dominant." << endl;
        cout << "The Jacobi method is not guaranteed to converge." << endl;
    }

    cout << "\nEnter the allowed error tolerance (e.g., 0.0001): ";
    cin >> allowed_error;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;

    cout << "\n--- Iteration Process ---" << endl;

    // 5. Iteratively solve for x
    int k; // Iteration counter
    for (k = 0; k < max_iterations; ++k) {
        float max_error = 0.0;

        for (int i = 0; i < n; ++i) {
            float sum = 0.0;

            // Calculate the sum part: Σ(a[i][j] * x[j]) for j != i
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum += a[i][j] * x[j];
                }
            }

            // Calculate the new value for x[i]
            x_new[i] = (b[i] - sum) / a[i][i];

            // Find the maximum error for this iteration
            float current_error = fabs(x_new[i] - x[i]);
            if (current_error > max_error) {
                max_error = current_error;
            }
        }

        // Update the solution vector for the next iteration
        x = x_new;

        // Optional: Print the state of the current iteration
        cout << "Iteration " << k + 1 << ": ";
        for(int i = 0; i < n; ++i) cout << "x[" << i+1 << "]=" << fixed << setprecision(5) << x[i] << " ";
        cout << "| Error = " << max_error << endl;

        // Check for convergence
        if (max_error < allowed_error) {
            cout << "\nConvergence achieved after " << k + 1 << " iterations." << endl;
            break;
        }
    }

    if (k == max_iterations) {
        cout << "\nMaximum iterations reached without converging to the desired tolerance." << endl;
    }

    // 6. Display the final solution
    cout << "\n------------------------------------" << endl;
    cout << fixed << setprecision(6); // Set final output precision
    printSolution(x);
    cout << "------------------------------------" << endl;

    return 0;
}
