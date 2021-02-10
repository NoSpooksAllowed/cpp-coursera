#pragma once
#include <string>
#include <map>

class Person {
public:
    void ChangeFirstName(int year, const std::string& firstName); 

    void ChangeLastName(int year, const std::string& lastName); 

    std::string GetFullName(int year); 

private:
    std::map<int, std::string> firstNameData;
    std::map<int, std::string> lastNameData;

    std::string GetDataFromMap(int year, const std::map<int, std::string>& m); 
};

