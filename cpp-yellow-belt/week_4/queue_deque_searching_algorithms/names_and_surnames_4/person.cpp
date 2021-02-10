#include "person.h"

void Person::ChangeFirstName(int year, const std::string& firstName) {
    firstNameData[year] = firstName;
}

void Person::ChangeLastName(int year, const std::string& lastName) {
    lastNameData[year] = lastName;
}

std::string Person::GetFullName(int year) {
    std::string firstName = GetDataFromMap(year, firstNameData);
    std::string lastName = GetDataFromMap(year, lastNameData);
    
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

std::string Person::GetDataFromMap(int year, const std::map<int, std::string>& m) {
    auto it = m.upper_bound(year);
    int query = year;

    if (!m.empty() && prev(it)->first <= year) {
        query = prev(it)->first;
    }

    if (m.count(query) == 0) {
        return "";
    }

    return m.at(query);
}

