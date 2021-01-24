#include <iostream>
#include <algorithm>

//#include "compute_median_age.h"
//#include "person.h"

void PrintStats(std::vector<Person> persons) {
    std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end())
        << std::endl;

    auto female_bond = std::partition(persons.begin(), persons.end(), 
        [](const Person& p) {
            return p.gender == Gender::FEMALE;
    });

    std::cout << "Median age for females = " << ComputeMedianAge(persons.begin(), female_bond)
        << std::endl;

    auto male_bond = std::partition(persons.begin(), persons.end(),
        [](const Person& p) {
            return p.gender == Gender::MALE;
    });

    std::cout << "Median age for males = " << ComputeMedianAge(persons.begin(), male_bond)
        << std::endl;

    auto female_employed_bond = std::partition(persons.begin(), persons.end(),
        [](const Person& p) {
            return p.gender == Gender::FEMALE && p.is_employed == true;
    });

    std::cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), female_employed_bond)
        << std::endl;

    auto unemployed_female_bond = std::partition(persons.begin(), persons.end(),
        [](const Person& p) {
            return p.gender == Gender::FEMALE && p.is_employed == false;
    });

    std::cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), unemployed_female_bond)
        << std::endl;

    auto employed_male_bond = std::partition(persons.begin(), persons.end(),
        [](const Person& p) {
            return p.gender == Gender::MALE && p.is_employed == true;
    });

    std::cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), employed_male_bond)
        << std::endl;

    auto unemployed_male_bond = std::partition(persons.begin(), persons.end(), 
        [](const Person& p) {
            return p.gender == Gender::MALE && p.is_employed == false;
    });

    std::cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), unemployed_male_bond)
        << std::endl;
}
