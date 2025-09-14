#include<bits/stdc++.h>
using namespace std;

// Function to print the matrix for visualization
void printMatrix(const vector<vector<double>>& matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << setw(10) << fixed << setprecision(3) << matrix[i][j] << " ";
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

    // 3. Forward Elimination to form an upper triangular matrix
    // This process converts the matrix into row echelon form.
    for (int k = 0; k < n - 1; ++k) { // k is the pivot row
        // Check for zero pivot. The simple algorithm fails if this happens.
        if (a[k][k] == 0) {
            cerr << "Error: Zero pivot element encountered at a[" << k + 1 << "][" << k + 1 << "]." << endl;
            cerr << "Pivoting is required to solve this system." << endl;
            return 1; // Exit with an error
        }

        for (int i = k + 1; i < n; ++i) { // i is the row to be transformed
            double factor = a[i][k] / a[k][k];
            for (int j = k; j < n + 1; ++j) { // j is the column in the current row
                a[i][j] = a[i][j] - factor * a[k][j];
            }
        }
    }

    cout << "\nMatrix after Forward Elimination (Upper Triangular Form):" << endl;
    printMatrix(a, n);

    // 4. Back Substitution (User called it Forward Substitution)
    // Compute x[n-1] (last variable) first
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    // Compute the remaining variables by substituting backwards
    for (int k = n - 2; k >= 0; --k) { // Iterate backwards from the second to last row
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
