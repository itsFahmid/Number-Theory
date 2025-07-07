    #include<bits/stdc++.h>
    using namespace std;

    float f(float x){
        return pow(x, 4) - 1156 * pow(x, 2) + 244036;
    }

    int main(){
        float a, b, x;
        cin >> a >> b;

        if(f(a) * f(b) < 0){
                x = a - ( (f(a) * (b - a)) / (f(b) - f(a)) );
            while(abs(a - b) / 2 > 0.00001){
                cout << a << " " << f(a) << " " << b << " " << f(b) << " " << x << " " << f(x) << endl;
                if(f(a) * f(x) < 0){
                    b = x;
                }
                else{
                    a = x;
                }
                x = a - ( (f(a) * (b - a)) / (f(b) - f(a)) );

            }
        }
        cout << x << endl;
    }
