#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int n;

    cin >> n;

    for (int i = 0; n > 0; i++) {
        v.push_back(n % 2);
        n /= 2;
    }

    for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) {
        cout << v[i];
    }

    cout << endl;

    return 0;
}
