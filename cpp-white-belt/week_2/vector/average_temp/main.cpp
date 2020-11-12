#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    
    cin >> n;

    vector<int> v(n);

    for (int& elem : v) {
        cin >> elem;
    }

    int average = accumulate(v.begin(), v.end(), 0) / v.size(); 
    int daysHigherAverage = 0;
    
    for (int elem : v) {
        if (elem > average) {
            daysHigherAverage++;
        }
    }

    cout << daysHigherAverage << endl;

    for (unsigned i = 0; i < v.size(); i++) {
        if (v[i] > average) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
