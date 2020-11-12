#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string s);

vector<string> PalindromFilter(vector<string> w, int minLength);

bool IsPalindrom(string s) {
    for (unsigned i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

vector<string> PalindromFilter(vector<string> w, int minLength) {
    vector<string> res;
    for (auto s : w) {
        if (IsPalindrom(s) == true && s.size() >= (unsigned)minLength) {
            res.push_back(s);
        }
    }

    return res;
}
