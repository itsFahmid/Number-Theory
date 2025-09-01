#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    cout << "enter the value of x: " << endl;
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    cout << "enter the value of y: " << endl;
    for(int i=0; i<n; i++){
        cin >> y[i];
    }
    double xp, yp = 0;
    cout << "enter the value of given x: " << endl;
    cin >> xp;
    for(int i=0; i<n; i++){
        double p = 1;
        for(int j=0; j<n; j++){
            if(i != j){
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }
    cout << yp << endl;
}
