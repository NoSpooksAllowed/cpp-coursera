#include <iostream>

using namespace std;

int main() {
    double n;
    double a, b;
    double x, y;

    cin >> n;
    cin >> a >> b;
    cin >> x >> y;

    if (n > a && n <= b) {
        n = n - (n * (x / 100));
    } else if (n > b) {
        n = n - (n * (y / 100));
    }

    cout << n << endl;

    return 0;
}
