#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> uniqueStr;
    int queries;
    string s;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> s;

        uniqueStr.insert(s);    
    }

    cout << uniqueStr.size() << endl;

    return 0;
}
