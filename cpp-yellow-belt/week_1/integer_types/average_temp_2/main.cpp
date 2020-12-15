#include <iostream>
#include <vector>
#include <numeric>
#include <cstdint>

using namespace std;

int main() {
    int n;
    int64_t sum = 0;
    cin >> n;

    vector<int> v(n);

    for (int& elem : v) {
        cin >> elem;
        sum += elem;
    }

    int64_t average = sum / static_cast<int64_t>(v.size());  
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
