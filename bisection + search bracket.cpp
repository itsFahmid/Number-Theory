#include <bits/stdc++.h>
using namespace std;

vector<double> poly = {1.0, -4.0, -10.0};

double search_bracket(){
    return fabs(sqrt(fabs(pow((poly[1] / poly[0]), 2) - 2 * (poly[2] / poly[0]))));
}

double f(double x){
    int n = poly.size();
    double result = poly[0]; // Initialize result

    //Horner's method
    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

vector<int> decartes(){     // determines the maximum possible number of positive real roots
    int c = 0;
    int n = poly.size();
    for(int i=0; i<n - 1; i++){
        if(poly[i]* poly[i - 1] < 0){
            c++;
        }
    }
    while(c >  0){
        cout << c << " ";
        c -= 2;
    }
}

int main() {
    double a, b, dx, da, mid, e;

    a =  search_bracket();// search bracket
    b = -a;

    cout << "please input incremental interval: ";
    cin >> dx; // step size

    da = a - dx;
    e = dx;

    cout << fixed << setprecision(6);


    while (a > b) {
        if (f(a) * f(da) < 0) {
            while (e > 0.00001) {
                e = fabs((a - da) / da);
                mid = (a + da) / 2;
                if (fabs(f(mid)) < 1e-9) {
                    break;
                }
                if (f(mid) * f(a) < 0) {
                    da = mid;
                } else {
                    a = mid;
                }
            }
            cout << "Root: " << mid << endl;
        }
        a = da;
        da = a - dx;
    }
}
