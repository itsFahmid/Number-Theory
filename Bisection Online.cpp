#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return pow(x, 4) - 1156 * pow(x, 2) + 244036;
}

int main(){
    double a, b, mid;
    cin >> a >> b;

    if(f(a)*f(b) < 0){
            mid = (a + b) / 2;
        while(abs(a - b) / 2 > 0.00001){
            cout << a << " " << f(a) << " " << b << " " << f(b) << " " << mid << " " << f(mid) << endl;
            if(f(a) * f(mid) < 0){
                b = mid;
            }
            else{
                a = mid;
            }
            mid = (a + b) / 2;
        }
    }

    cout << mid;
}
