#include<bits/stdc++.h>
using namespace std;

vector<int> coeff = {1 -7, 12, 4, 16};

void decartes_for_neg(){
    int c = 0, n = coeff.size();
    for(int i = 0, i < n - 1, i++){
        if(coeff[i]*coeff[i + 1] > 0){
            c++;
        }
    }
    while(c > 0){
        cout << c << " ";
        c-=2;
    }
}

double f(double x){
    n = coeff.size();
    double r = coeff[0];
    for(int i=0, i< n; i++){
        r = r * x + coeff[i];
    }
    return r;
}

double df(double x){
    n = coeff.size() - 1;
    double r = coeff[0];
    for(int i=0, i< n; i++){
        r = r * x * (n - i + 1)+ coeff[i];
    }
    return r;
}

double Search_Bracket(){
    return sqrt ( pow(coeff[1] / coeff[0], 2) - 2 * (coeff[2] / coeff[1]) );
}

double newton_raphson(double x){
    return (x - (f(x) / df(x)));
}

int main(){
    int iter = 1, rootno = 1;
    double x2, x1, x0;


}
