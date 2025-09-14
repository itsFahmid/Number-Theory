#include<iostream>
#include<vector>
#include<iomanip> // For setw, setprecision, fixed
#include<cmath>    // For abs
#include<algorithm> // For swap

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
    // 1. Declare variables and read the order of the matrix n.
    int n;
    cout << "Enter the order of the matrix (number of equations): ";
    cin >> n;

    // The augmented matrix will have n rows and n+1 columns
    vector<vector<double>> a(n, vector<double>(n + 1));
    vector<double> x(n); // Solution vector

    // 2. Take the coefficients of the linear equation as input
    cout << "Enter the coefficients of the augmented matrix [A|b]:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "For equation " << i + 1 << ":" << endl;
        for (int j = 0; j < n + 1; ++j) {
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

    // 3. Forward Elimination with Partial Pivoting
    for (int k = 0; k < n - 1; ++k) { // k is the current pivot column

        // --- PIVOTING START ---
        // Find the row with the largest absolute value in the current column (k)
        int pivot_row = k;
        for (int i = k + 1; i < n; ++i) {
            if (abs(a[i][k]) > abs(a[pivot_row][k])) {
                pivot_row = i;
            }
        }

        // If the pivot row with the max element is not the current row, swap them
        if (pivot_row != k) {
            cout << "\n-> Pivoting: Swapping row " << k + 1 << " with row " << pivot_row + 1 << "..." << endl;
            swap(a[k], a[pivot_row]);
            cout << "   Matrix after pivot:" << endl;
            printMatrix(a, n);
        }
        // --- PIVOTING END ---

        // Check for a singular or nearly singular matrix after pivoting
        // Use a small tolerance instead of '== 0' for floating-point numbers
        if (abs(a[k][k]) < 1e-9) {
            cerr << "Error: The matrix is singular or nearly singular." << endl;
            cerr << "A unique solution does not exist." << endl;
            return 1; // Exit with an error
        }

        // Proceed with elimination for the rows below the pivot
        for (int i = k + 1; i < n; ++i) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j < n + 1; ++j) {
                a[i][j] = a[i][j] - factor * a[k][j];
            }
        }
    }

    cout << "\nMatrix after Forward Elimination (Upper Triangular Form):" << endl;
    printMatrix(a, n);

    // 4. Back Substitution
    // Check if the last pivot element is zero (indicates no unique solution)
    if (abs(a[n - 1][n - 1]) < 1e-9) {
        cerr << "Error: No unique solution exists for the system." << endl;
        return 1;
    }

    // Compute x[n-1] (last variable) first
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    // Compute the remaining variables by substituting backwards
    for (int k = n - 2; k >= 0; --k) {
        double sum = 0;
        for (int j = k + 1; j < n; ++j) {
            sum = sum + a[k][j] * x[j];
        }
        x[k] = (a[k][n] - sum) / a[k][k];
    }

    // 5. Print the solution vector
    cout << "\nSolution Vector {x1, x2, ..., xn}:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(4) << x[i] << endl;
    }

    // 6. Stop
    return 0;
}
