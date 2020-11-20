#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& firstName) {
        firstNameData[year] = firstName;
    }

    void ChangeLastName(int year, const string& lastName) {
        lastNameData[year] = lastName;
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

private:
    map<int, string> firstNameData;
    map<int, string> lastNameData;

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
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
