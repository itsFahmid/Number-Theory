#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> x(n);
    vector<vector<double>> y(n, vector<double>(n));
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    for(int i=0; i<n; i++){
        cin >> y[i][0];
    }
    double xp;
    cin >> xp;

    for(int j=1; j<n; j++){
        for(int i=0; i<n - j; i++){
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j]-x[i]);
        }
    }
    double yp = y[0][0];
    for(int i=1; i<n; i++){
        double term = 1;
        for(int j=0; j<i; j++){
            yp += term * y[0][i];
        }
    }
    cout << yp << endl;
}
