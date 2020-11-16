#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& s);

int main() {
    string s1, s2;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;

        if (BuildCharCounters(s1) == BuildCharCounters(s2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

map<char, int> BuildCharCounters(const string& s) {
    map<char, int> res;

    for (const char& ch : s) {
        res[ch]++;
    }

    return res;
}
