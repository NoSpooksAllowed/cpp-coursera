#include <iostream>
#include <string>


using namespace std;

int main() {
    string s;
    int j = -2;

    cin >> s;
    
    for (unsigned i = 0; i < s.size(); i++) {
        if (s[i] == 'f' && j == -2) {
            j = -1;
        } else if (s[i] == 'f' && j == -1) {
            j = i;
            break;
        }
    }

    cout << j << endl;

    return 0;
}
