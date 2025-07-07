
#include<bits/stdc++.h>
using namespace std;

float f(float x){
    return x * x - 4 * x - 10;
    //return exp(x) - 3 * x;
}

int main(){
    float x0, x1, x2;
    cout << "pls enter the constants of xn, xn-1, xn-2" << endl;
    cin >> x0 >> x1 >> x2;
    float b = sqrt( pow((x1 / x0), 2) - 2 * (x2  / x0) );
    float a = -b;
    float mid;

    cout << a << endl;

    if(f(a) * f(b) < 0){
        while(abs(b - a) > 0.01){
            mid = (a + b) / 2;
            if(f(mid) == 0){
                cout << mid;
                break;
            }

            if(f(mid) * f(a) < 0){
                b = mid;
            }
            else{
                a = mid;
            }
        }
        cout << mid;
    }
    else{
        cout << "No root between intervals";
    }
}
