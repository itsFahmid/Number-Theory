#include<bits/stdc++.h>
using namespace std;

vector<int> coeff = {1 -7, 12, 4, 16};

void decartes_for_neg(){
    int c = 0, n = coeff.size();
    vector<double> neg_coeff(n);
    for(int i=0; i<n; i++){
        if(i % 2 == 1){
            neg_coeff[i] = -coeff[i];
        }
        else{
            neg_coeff[i] = coeff[i];
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(neg_coeff[i]*neg_coeff[i + 1] < 0){
            c++;
        }
    }
    while(c > 0){
        cout << c << " ";
        c-=2;
    }
}
void decartes_for_pos(){
    int c = 0, n = coeff.size();
    for(int i = 0; i < n - 1; i++){
        if(coeff[i]*coeff[i + 1] < 0){
            c++;
        }
    }
    while(c > 0){
        cout << c << " ";
        c-=2;
    }
}

double f(double x){
    int n = coeff.size();
    double r = coeff[0];
    for(int i=0; i< n; i++){
        r = r * x + coeff[i];
    }
    return r;
}

double df(double x){
    int n = coeff.size() - 1;
    double r = coeff[0];
    for(int i=0; i< n; i++){
        r = r * x * (n - i + 1)+ coeff[i];
    }
    return r;
}

double cauchy(){
    int n = coeff.size();
    double r, maxi = -1e9;
    for(int i=1; i<n; i++){
        if(maxi < fabs(coeff[i]) ){
            maxi = fabs(coeff[i]);
        }
    }
    return (1 + (coeff[0] / maxi) );
}

void synthetic_division(){
    int n = coeff.size();
    vector<double> changed_coeff(n - 1);

    for(int i=0; i<n; i++){

    }
}

double Search_Bracket(){
    return sqrt ( pow(coeff[1] / coeff[0], 2) - 2 * (coeff[2] / coeff[1]) );
}

double newton_raphson(double x){
    return (x - (f(x) / df(x)));
}

int main(){
    int iter = 1, rootno = 1, n = coeff.size(), c = 1;
    double x2, x1, x0, error, tolerance = 0.00001;

    double a = Search_Bracket(), b = -a;

    while(n > 1){
        error = 100;    // just an initial guess;

        cout << "converging for root no: " << c << endl << endl;
        while(error > tolerance){
            x2 = newton_raphson(x1);
        }

        n--;
        c++;
    }

}
