#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;
    
    cin >> a >> b >> c;

    if (a == 0 && b != 0) {
        double x = (-c) / b;
        cout << x << endl;
    } else if (a == 0 && b == 0) {
        cout << " " << endl;
    } else {
        double d = (b*b) - (4*a*c);

        if (d > 0) {
            double x1 = (-b + sqrt(d)) / (2*a);
            double x2 = (-b - sqrt(d)) / (2*a);
            cout << x1 << " " << x2 << endl;
        } else if (d == 0) {
            double x = (-b) / (2*a);
            cout << x << endl;
        } else {
            cout << " " << endl;
        }
    }
    return 0;
}
