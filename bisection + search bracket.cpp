#include <bits/stdc++.h>
using namespace std;

vector<double> poly = {1.0, -4.0, -10.0};

double search_bracket(){
    return fabs(sqrt(fabs(pow((poly[1] / poly[0]), 2) - 2 * (poly[2] / poly[0]))));
}

double f(double x){    // using horner
    int n = poly.size();
    double result = poly[0]; // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (int i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

int main() {
    double a, b, dx, da, mid;

    a =  search_bracket();// search bracket
    b = -a;

    cout << "please input incremental interval: ";
    cin >> dx; // step size

    da = a - dx;

    while (a > b) { // FIX: loop condition was wrong
        if (f(a) * f(da) < 0) {
            while (fabs(a - da) > 0.00001) {
                mid = (a + da) / 2;
                if (fabs(f(mid)) < 1e-9) { // FIX: avoid double equality check
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
        a = da;     // FIX: move interval forward
        da = a - dx;
    }
}
