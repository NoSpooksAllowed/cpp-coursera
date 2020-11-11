#include <iostream>

using namespace std;

int Factorial(int x);

int main() {
    int a;

    cin >> a;

    cout << Factorial(a) << endl;

    return 0;
}

int Factorial(int x) {
    if (x <= 1) {
        return 1;
    }

    return x * Factorial(x - 1); 
}
