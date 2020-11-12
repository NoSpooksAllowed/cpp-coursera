#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v);
void printVector(const vector<int>& v);

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};

    vector<int> res = Reversed(numbers);
    printVector(res);

    return 0;
}

vector<int> Reversed(const vector<int>& v) {
    vector<int> res;

    for (int i = static_cast<int>(v.size() - 1); i >= 0; i--) {
        res.push_back(v[i]);
    }

    return res;
}

void printVector(const vector<int>& v) {
    for (auto elem : v) {
        cout << elem << " ";
    }

    cout << endl;
}
