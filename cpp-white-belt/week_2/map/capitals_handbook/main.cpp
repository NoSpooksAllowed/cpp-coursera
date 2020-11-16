#include <iostream>
#include <map>
#include <string>

using namespace std;
void dumpCapitals(const map<string, string>& capitals);
void changeCapital(map<string, string>& capitals);
void renameCountry(map<string, string>& capitals);
void aboutCountry(const map<string, string>& capitals);

int main() {
    map<string, string> capitals;
    string command;
    int queries;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> command;

        if (command == "CHANGE_CAPITAL") {
            changeCapital(capitals);
        } else if (command == "RENAME") {
            renameCountry(capitals);
        } else if (command == "ABOUT") {
            aboutCountry(capitals);
        } else if (command == "DUMP") {
            dumpCapitals(capitals);
        }
    }
    return 0;
}

void dumpCapitals(const map<string, string>& capitals) {
    if (capitals.size() == 0) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto& [key, value] : capitals) {
            cout << key << "/" << value << " ";
        }
        cout << endl;
    }
}

void changeCapital(map<string, string>& capitals) {
    string country;
    string newCapital;
    cin >> country >> newCapital;

    if (capitals.count(country) == 0) {
        cout << "Introduce new country " << country << " with capital " << newCapital << endl;
        
        capitals[country] = newCapital; 
    } else if (capitals[country] == newCapital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
    } else {
        cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << newCapital << endl;

        capitals[country] = newCapital;
    }
}

void renameCountry(map<string, string>& capitals) {
    string oldCountryName;
    string newCountryName;

    cin >> oldCountryName >> newCountryName;

    if (oldCountryName == newCountryName || capitals.count(oldCountryName) == 0
            || capitals.count(newCountryName) == 1) {
        cout << "Incorrect rename, skip" << endl;
    } else {
        cout << "Country " << oldCountryName << " with capital " << capitals[oldCountryName] << " has been renamed to " << newCountryName << endl;

        string tmp = capitals[oldCountryName];
        
        capitals.erase(oldCountryName);

        capitals[newCountryName] = tmp; 
    }
}

void aboutCountry(const map<string, string>& capitals) {
    string country;

    cin >> country;
    if (capitals.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
    } else {
        cout << "Country " << country << " has capital " << capitals.at(country) << endl;
    }
}
