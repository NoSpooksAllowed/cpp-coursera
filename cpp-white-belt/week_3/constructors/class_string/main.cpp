#include <vector>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class ReversibleString {
public:
    ReversibleString() {}

    ReversibleString(const string& s1) {
        s = s1;
    } 

    const string& ToString() const {
        return s;
    }

    void Reverse() {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }        
    }
private:
    string s;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;
  
    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;
  
    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;
  
    return 0;
}
