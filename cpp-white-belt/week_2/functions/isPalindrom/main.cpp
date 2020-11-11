#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string s);

int main() {
    string s;

    cin >> s;

    cout << IsPalindrom(s) << endl;

    return 0;
}

bool IsPalindrom(string s) {
    for (unsigned i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}
