#include<bits/stdc++.h>
using namespace std;

vector<double> coeff = {5, -20, 6, 7, -43, -2, 5, 6};

void decartes(){
    int n = coeff.size(), c = 0;
    for(int i=0; i<n; i++){
        if(coeff[i] * coeff[i + 1] < 0){
            c++;
        }
    }

    while(c > 0){
        cout << c << " ";
        c -= 2;
    }
    cout << endl;
}

double f(double x){
    double r = coeff[0], n = coeff.size();
    for(int i=1; i<n; i++){
        r = r * x + coeff[i];
    }
    return r;
}

int main(){
    decartes();
    cout << f(5.0);
}
