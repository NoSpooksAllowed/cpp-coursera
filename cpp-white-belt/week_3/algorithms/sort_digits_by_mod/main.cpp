#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    vector<int> v;
    int queries;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(begin(v), end(v), [](int a, int b) {
        return (abs(a) < abs(b));
    });

    for (const auto& i : v) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
