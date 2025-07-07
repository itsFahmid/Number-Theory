#include<bits/stdc++.h>
using namespace std;

float f(float x){
    return x * x - 4 * x - 10;
}

int main(){
    float a, b;
    float mid;
    cin >> a >> b;

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
