#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

void addWord(map<string, set<string>>& synonyms);
void countWord(const map<string, set<string>>& synonyms);
void checkSynonyms(const map<string, set<string>>& synonyms);

int main() {
    map<string, set<string>> synonyms;
    int queries;
    string command;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> command;

        if (command == "ADD") {
            addWord(synonyms);
        } else if (command == "COUNT") {
            countWord(synonyms);
        } else if (command == "CHECK") {
            checkSynonyms(synonyms);
        }
    }


    return 0;
}

void addWord(map<string, set<string>>& synonyms) {
    string s1, s2;

    cin >> s1 >> s2;

    synonyms[s1].insert(s2);
    synonyms[s2].insert(s1);
}

void countWord(const map<string, set<string>>& synonyms) {
    string s;

    cin >> s;
    
    if (synonyms.count(s) == 0) {
        cout << 0 << endl;
    } else {
        cout << synonyms.at(s).size() << endl;
    }
}

void checkSynonyms(const map<string, set<string>>& synonyms) {
    string s1, s2;

    cin >> s1 >> s2;
    if (synonyms.count(s1) == 0) {
        cout << "NO" << endl;
    } else if (synonyms.at(s1).count(s2) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
