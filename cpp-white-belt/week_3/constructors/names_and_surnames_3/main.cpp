#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Person {
public:
    Person(const string& firstName, const string& lastName, int year) {
        firstNameData[year] = firstName;
        firstNameYears.push_back(year);
        lastNameData[year] = lastName;
        lastNameYears.push_back(year);

        birth = year;
    }
    void ChangeFirstName(int year, const string& firstName) {
        if (year >= birth) {
            firstNameData[year] = firstName;
            firstNameYears.push_back(year);
        }
    }

    void ChangeLastName(int year, const string& lastName) {
        if (year >= birth) {
            lastNameData[year] = lastName;
            lastNameYears.push_back(year);
        }
    }

    string GetFullName(int year) const {
        if (year < birth) {
            return "No person";
        }

        const string firstName = GetDataFromMap(year, firstNameData);
        const string lastName = GetDataFromMap(year, lastNameData);
    
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

    string GetFullNameWithHistory(int year) const {
        if (year < birth) {
            return "No person";
        }

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
    int birth;

    string GetHistory(int year, const map<int, string>& m, const vector<int>& y) const {
        vector<string> names;
        vector<int> copyYears = y;

        int minYear = year;
        sort(copyYears.begin(), copyYears.end(), [](const int a, const int b) {return a > b; });
        copyYears.erase( unique(copyYears.begin(), copyYears.end()), copyYears.end() ); // sort and dedup vector

        for (const auto& [key, value] : m) {
            if (key <= year) {
                minYear = key;
            }
        }

        for (unsigned i = 0; i < copyYears.size(); i++) {
            if (i != 0 && m.at(copyYears[i - 1]) == m.at(copyYears[i])) {
                continue; 
            }

            if (copyYears[i] < minYear) {
                names.push_back(m.at(copyYears[i]));
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
    string GetDataFromMap(int year, const map<int, string>& m) const {
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
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
  
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
