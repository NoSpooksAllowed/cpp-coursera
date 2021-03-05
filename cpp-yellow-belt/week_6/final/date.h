#pragma once
#include "helpers.h"

class Date {
public:
    Date();

    Date(
        const int new_year, 
        const int new_month, 
        const int new_day
    );
    
    int GetYear() const;

    int GetMonth() const;

    int GetDay() const; 

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);


bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);


bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& output, const Date& date);

Date ParseDate(std::istream& input);
