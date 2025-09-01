#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    vector<double> x(n), y(n);

    for(int i=0;i<n;i++){
        cin >> x[i];
    }

    for(int i=0;i<n;i++){
        cin >> y[i];
    }

    vector<double> X(2*d+1);
    for(int k=0;k<=2*d;k++){
        for(int i=0;i<n;i++) X[k]+=pow(x[i],k);
    }

    vector<double> B(d+1);
    for(int k=0;k<=d;k++){
        for(int i=0;i<n;i++) B[k]+=pow(x[i],k)*y[i];
    }

    vector<vector<double>> A(d+1, vector<double>(d+2));
    for(int i=0;i<=d;i++){
        for(int j=0;j<=d;j++) A[i][j]=X[i+j];
        A[i][d+1]=B[i];
    }

    // Gaussian elimination part
    for(int i=0;i<=d;i++){
        for(int j=i+1;j<=d;j++){
            double ratio=A[j][i]/A[i][i];
            for(int k=0;k<=d+1;k++) A[j][k]-=ratio*A[i][k];
        }
    }

    vector<double> coef(d+1);
    for(int i=d;i>=0;i--){
        coef[i]=A[i][d+1];
        for(int j=i+1;j<=d;j++) coef[i]-=A[i][j]*coef[j];
        coef[i]/=A[i][i];
    }

    for(double c:coef){
        cout<<c<<" ";
    }
    cout<<"\n";
}

