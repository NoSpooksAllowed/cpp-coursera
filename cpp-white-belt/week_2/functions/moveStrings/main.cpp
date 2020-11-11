#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& dest);
void printStrings(const vector<string>& words);

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    
    MoveStrings(source, destination);

    printStrings(destination);
    return 0;
}

void MoveStrings(vector<string>& source, vector<string>& dest) {
    for (auto s : source) {
        dest.push_back(s);
    }
    source.clear();
}

void printStrings(const vector<string>& words) {
    for (auto s : words) {
        cout << s << " ";
    }
    cout << endl;
}
