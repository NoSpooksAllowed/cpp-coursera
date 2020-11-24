#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& firstName) {
        firstNameData[year] = firstName;
        firstNameYears.push_back(year);
    }

    void ChangeLastName(int year, const string& lastName) {
        lastNameData[year] = lastName;
        lastNameYears.push_back(year);
    }

    string GetFullName(int year) {
        string firstName = GetDataFromMap(year, firstNameData);
        string lastName = GetDataFromMap(year, lastNameData);
    
        if (firstName.size() == 0 && lastName.size() == 0) {
            return "Incognito";
        } else if (firstName.size() == 0) {
            return lastName + " with unknown first name"; 
        } else if (lastName.size() == 0) {
            return firstName + " with unknown last name";
        } else {
            return firstName + " " + lastName;
        }
    }

    string GetFullNameWithHistory(int year) {
        string firstName = GetDataFromMap(year, firstNameData);
        string lastName = GetDataFromMap(year, lastNameData);
        string firstNameHistory = GetHistory(year, firstNameData, firstNameYears);
        string lastNameHistory = GetHistory(year, lastNameData, lastNameYears);

        if (firstName.size() == 0 && lastName.size() == 0) {
            return "Incognito";
        } else if (firstName.size() == 0) {
            return lastName + lastNameHistory +  " with unknown first name"; 
        } else if (lastName.size() == 0) {
            return firstName + firstNameHistory + " with unknown last name";
        } else {
            return firstName + firstNameHistory + " " + lastName + lastNameHistory;
        }
    }
private:
    map<int, string> firstNameData;
    map<int, string> lastNameData; 
    vector<int> firstNameYears;
    vector<int> lastNameYears;

    string GetHistory(int year, const map<int, string>& m, vector<int>& y) {
        vector<string> names;
        
        int minYear = year;
        sort(y.begin(), y.end(), [](const int a, const int b) {return a > b; });
        y.erase( unique(y.begin(), y.end()), y.end() ); // sort and dedup vector

        for (const auto& [key, value] : m) {
            if (key <= year) {
                minYear = key;
            }
        }

        for (unsigned i = 0; i < y.size(); i++) {
            if (i != 0 && m.at(y[i - 1]) == m.at(y[i])) {
                continue; 
            }

            if (y[i] < minYear) {
                names.push_back(m.at(y[i]));
            }
        }

        if (names.size() == 0) {
            return "";
        } else {
            return " (" + accumulate(names.begin(), names.end(), std::string(), 
                    [](const std::string& a, const std::string& b) -> std::string {
                        return a + (a.length() > 0 ? ", " : "") + b;
                    }) + ")";
        }

    }
    string GetDataFromMap(int year, const map<int, string>& m) {
        int querie = year;

        for (const auto& [key, value] : m) {
            if (key <= year) {
                querie = key;
            }
        }

        if (m.count(querie) == 0) {
            return "";
        } else {
            return m.at(querie);
        }
    }

};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1965, "Appolinaria");

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1965, "Volkova");
    person.ChangeLastName(1965, "Volkova-Sergeeva");

    for (int year : {1964, 1965, 1966}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
