#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    double n;
    
    cout << fixed << setprecision(3); 
    if (input) {
        while (input >> n) {
            cout << n << endl;
        }    
    }
    return 0;
}
