#include <bits/stdc++.h>
using namespace std;

// Function to print the matrix for visualization
void printMatrix(const vector<vector<double>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << setw(12) << fixed << setprecision(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 1. Declare the variables and read the order of the matrix n.
    int n;
    cout << "Enter the order of the matrix (number of equations): ";
    cin >> n;

    // The augmented matrix will have n rows and n+1 columns
    vector<vector<double>> a(n, vector<double>(n + 1));
    vector<double> x(n); // Solution vector

    // 2. Take the coefficients of the linear equation as input
    cout << "Enter the coefficients of the augmented matrix [A|b]:" << endl;
    for (int i = 0; i < n; ++i) { // access the rows (0-indexed)
        cout << "For equation " << i + 1 << ":" << endl;
        for (int j = 0; j < n + 1; ++j) { // access the columns (0-indexed)
            if (j < n) {
                cout << "  Enter coefficient a[" << i + 1 << "][" << j + 1 << "]: ";
            } else {
                cout << "  Enter constant b[" << i + 1 << "]: ";
            }
            cin >> a[i][j];
        }
    }

    cout << "\nInitial Augmented Matrix:" << endl;
    printMatrix(a, n);

    // 3. Apply Gauss Jordan Elimination on Matrix a
    for (int i = 0; i < n; ++i) { // i is the pivot row
        // --- Partial Pivoting Start ---
        // Find the row with the largest element in the current column (i).
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(a[k][i]) > abs(a[max_row][i])) {
                max_row = k;
            }
        }

        // Swap the current row (i) with the row containing the largest pivot element.
        if (max_row != i) {
            swap(a[i], a[max_row]);
        }
        // --- Partial Pivoting End ---

        // Check if the pivot is zero after pivoting. If so, the matrix is singular.
        // We use a small tolerance instead of a direct == 0 check for floating-point stability.
        if (abs(a[i][i]) < 1e-9) {
            cout << "Mathematical Error: Matrix is singular or nearly singular." << endl;
            cout << "A unique solution does not exist." << endl;
            return 1; // Stop
        }

        // Normalize the pivot row 'i' so that the pivot element a[i][i] becomes 1.
        double pivot_val = a[i][i];
        for (int k = 0; k < n + 1; ++k) {
            a[i][k] = a[i][k] / pivot_val;
        }

        // Eliminate other entries in the pivot column 'i'.
        for (int j = 0; j < n; ++j) {
            if (i != j) { // Don't eliminate the pivot row itself.
                double factor = a[j][i];
                for (int k = 0; k < n + 1; ++k) {
                    a[j][k] = a[j][k] - factor * a[i][k];
                }
            }
        }
    }

    cout << "\nMatrix after Gauss-Jordan Elimination (Reduced Row Echelon Form):" << endl;
    printMatrix(a, n);

    // 4. Obtaining Solution
    // The solution is now in the last column of the matrix.
    for (int i = 0; i < n; ++i) {
        x[i] = a[i][n] / a[i][i]; // a[i][i] should be 1, but we include division for correctness.
    }

    // 5. Display Solution
    cout << "\nSolution Vector {x1, x2, ..., xn}:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(4) << x[i] << endl;
    }

    // 6. Stop
    return 0;
}
