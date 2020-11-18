#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

string caseInsensitive(const string& s);

int main() {
    vector<string> v;
    int queries;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(begin(v), end(v), [](string a, string b) {
        return (caseInsensitive(a) < caseInsensitive(b));
    });

    for (const auto& i : v) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

string caseInsensitive(const string& s) {
    string res = s;

    for (auto& c : res) {
        c = tolower(c);
    }

    return res;
}
