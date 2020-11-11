#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v);
void printVector(const vector<int>& v);

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};

    Reverse(numbers);

    printVector(numbers);

    return 0;
}

void Reverse(vector<int>& v) {
    for (unsigned int i = 0; i < v.size() / 2; i++) {
        int tmp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = tmp;
    }
}

void printVector(const vector<int>& v) {
    for (auto elem : v) {
        cout << elem << " ";
    }

    cout << endl;
}
